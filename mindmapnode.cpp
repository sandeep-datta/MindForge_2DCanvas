#include <QDebug>
#include "mindmapnode.h"



MindMapNode::MindMapNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
    , m_color(Qt::black)
    , m_updateTextBoundingRect(true)
{

}

QRectF MindMapNode::textBoundingRect(QPainter *painter)
{

    if (m_updateTextBoundingRect) {
        m_bounds = painter->boundingRect(m_bounds,
                                     Qt::TextWordWrap|Qt::TextDontClip,
                                     m_text);
        m_updateTextBoundingRect = false;
    }

    return m_bounds;

}

qreal MindMapNode::subTreeYSize(QPainter *painter)
{
    qreal ySize = 0.0;

    foreach(MindMapNode* child, m_children) {
        ySize += child->subTreeYSize(painter);
    }

    ySize += (m_children.length() - 1) * Y_MARGIN;


    auto br = textBoundingRect(painter);

    qreal textHeight = br.height();

    qreal retVal = qMax(ySize, textHeight);

    return retVal;
}


void MindMapNode::paint(QPainter *painter)
{
    m_bounds = textBoundingRect(painter);

    painter->setPen(QPen(m_color));

    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                  m_text, &m_bounds);

    painter->setPen(QPen(Qt::gray, 1));

    painter->drawLine(m_bounds.bottomLeft(), m_bounds.bottomRight());


    const qreal childX = m_bounds.left() + m_bounds.width() + X_MARGIN;

    const qreal cpX = m_bounds.right() + X_MARGIN / 2;

    qreal stySize = subTreeYSize(painter);

    qreal childY = m_bounds.top()
                    + m_bounds.height() / 2.0
                    - stySize / 2.0;

    foreach(MindMapNode* child, m_children) {
        QPainterPath path;

        qreal childSubTreeYSize = child->subTreeYSize(painter);
        childY += childSubTreeYSize / 2.0;

        childY -= child->textBoundingRect(painter).height()/2;

        child->moveTo(childX, childY);
        child->paint(painter);
        QPointF cp1(cpX, m_bounds.bottom());
        QPointF cp2(cpX, child->textBoundingRect(painter).bottom());
        const QPointF &end = child->textBoundingRect(painter).bottomLeft();

        path.moveTo(m_bounds.bottomRight());
        path.cubicTo(cp1, cp2, end);
        painter->drawPath(path);

        childY += child->textBoundingRect(painter).height()/2;
        childY += childSubTreeYSize / 2.0;
        childY += Y_MARGIN;
    }
}

void MindMapNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
    m_updateTextBoundingRect = true;
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

void MindMapNode::moveTo(qreal x, qreal y)
{
    m_bounds.moveTo(x, y);
}
