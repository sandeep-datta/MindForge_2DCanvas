#include "mindmapnode.h"

MindMapNode::MindMapNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
{

}

const QRectF MindMapNode::boundingRect(QPainter *painter) const
{

    return painter->boundingRect(m_bounds,
                           Qt::TextWordWrap|Qt::TextDontClip,
                           m_text);
}

void MindMapNode::paint(QPainter *painter)
{
    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                      m_text, &m_bounds);
}

void MindMapNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
}

void MindMapNode::addChild(MindMapNode *child)
{
    m_children.append(child);
}

void MindMapNode::setPos(qreal x, qreal y)
{
    m_bounds.setTopLeft(QPointF(x, y));
}
