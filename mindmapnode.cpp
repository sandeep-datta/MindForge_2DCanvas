#include <QDebug>
#include "mindmapnode.h"



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

    painter->save();

    painter->setPen(QPen(m_color));

    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                  m_text, &m_bounds);

    painter->drawLine(m_bounds.bottomLeft(), m_bounds.bottomRight());

    painter->restore();

    qreal childX = m_bounds.left() + m_bounds.width() + X_MARGIN;

    qreal stySize = subTreeYSize(painter);

    qreal childY = m_bounds.top()
                    + m_bounds.height() / 2.0
                    - stySize / 2.0;

    foreach(MindMapNode* child, m_children) {
        QPainterPath path;
        path.moveTo(m_bounds.bottomRight());


        qreal childSubTreeYSize = child->subTreeYSize(painter);
        childY += childSubTreeYSize / 2.0;

        childY -= child->textBoundingRect(painter).height()/2;
        child->moveTo(childX, childY);
        child->paint(painter);
        path.lineTo(child->textBoundingRect(painter).bottomLeft());
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
