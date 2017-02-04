#include "mindmapnode.h"

MindMapNode::MindMapNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
    , m_boundsValid(false)
{

}

const QRectF* MindMapNode::boundingRect() const
{
    if(!m_boundsValid) {
        return nullptr;
    }

    return &m_bounds;
}

void MindMapNode::paint(QPainter *painter, const QRectF& paintableArea)
{
    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                      m_text, &m_bounds);
    m_boundsValid = true;
}

void MindMapNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
    m_boundsValid = false;
}

void MindMapNode::setPos(const QPointF& pos)
{
    m_bounds.setTopLeft(pos);
}
