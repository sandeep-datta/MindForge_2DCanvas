#include <QDebug>
#include "mindmapnode.h"

int g_indents = 0;

void indent() {
    for (int i = 0; i < g_indents; i++) {
       qDebug("%s", "    ");
    }
}

#define ENTER() { \
    indent(); \
    qDebug()<< "Entering: " << __FUNCTION__ << endl; \
    g_indents++; \
}
#define EXIT() { \
    g_indents--; \
    indent(); \
    qDebug()<< "Exiting: " << __FUNCTION__ << endl; \
}
#define TRACE(X) {\
    indent(); \
    qDebug() << __LINE__ << ":" << #X << "=" << (X) << endl;\
}

MindMapNode::MindMapNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
    , m_color(Qt::black)
{

}

QRectF MindMapNode::textBoundingRect(QPainter *painter) const
{

    return painter->boundingRect(m_bounds,
                           Qt::TextWordWrap|Qt::TextDontClip,
                                 m_text);
}

qreal MindMapNode::subTreeYSize(QPainter *painter) const
{
    ENTER();

    TRACE(m_text);

    qreal ySize = 0.0;

    foreach(MindMapNode* child, m_children) {
        ySize += child->subTreeYSize(painter);
        TRACE(ySize);
    }

    ySize += (m_children.length() - 1) * Y_MARGIN;
    TRACE(ySize);

    TRACE(m_bounds);

    auto br = textBoundingRect(painter);

    TRACE(br);

    qreal textHeight = br.height();

    TRACE(textHeight);

    qreal retVal = qMax(ySize, textHeight);
    TRACE(retVal);

    EXIT();

    return retVal;
}


void MindMapNode::paint(QPainter *painter, qreal x, qreal y)
{
    ENTER();

    TRACE(m_text);

    setPos(x, y);

    m_bounds = textBoundingRect(painter);

    TRACE(m_bounds);

    painter->save();

    painter->setPen(QPen(m_color));

    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                  m_text, &m_bounds);

    painter->drawRect(m_bounds);

    painter->restore();

    TRACE(m_bounds);

    qreal childX = x + m_bounds.width() + X_MARGIN;

    TRACE(childX);

    qreal stySize = subTreeYSize(painter);

    TRACE(stySize);

    qreal childY = m_bounds.top()
                    + m_bounds.height() / 2.0
                    - stySize / 2.0;

    TRACE(childY);

    foreach(MindMapNode* child, m_children) {
        qreal childSubTreeYSize = child->subTreeYSize(painter);
        childY += childSubTreeYSize / 2.0;
        TRACE(childY);
        childY -= child->textBoundingRect(painter).height()/2;
        TRACE(childY);
        child->paint(painter, childX, childY);
        childY += child->textBoundingRect(painter).height()/2;
        TRACE(childY);
        childY += childSubTreeYSize / 2.0;
        TRACE(childY);
        childY += Y_MARGIN;
        TRACE(childY);
    }

    EXIT();
}

void MindMapNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
}

void MindMapNode::setColor(QColor color)
{
    m_color = color;
}

MindMapNode* MindMapNode::addChild(QString text, QColor color)
{
    auto child = new MindMapNode(this);
    child->setColor(color);
    child->setText(text);
    m_children.append(child);
    return child;
}

void MindMapNode::setPos(qreal x, qreal y)
{
    m_bounds.moveTo(x, y);
}
