#include "mmnode.h"

MmNode::MmNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
    , m_boundsValid(false)
{

}

const QRectF* MmNode::boundingRect() const
{
    if(!m_boundsValid) {
        return nullptr;
    }

    return &m_bounds;
}

void MmNode::paint(QPainter *painter)
{
    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                      m_text, &m_bounds);
    m_boundsValid = true;
}

void MmNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
    m_boundsValid = false;
}

void MmNode::setPos(const QPointF& pos)
{
    m_bounds.setTopLeft(pos);
}
