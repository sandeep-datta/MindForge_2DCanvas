#include "mindmapnode.h"

MindMapNode::MindMapNode(QObject *parent)
    : QObject(parent)
    , m_bounds(0.0, 0.0, MAX_WIDTH, 0.0)
{

}

const QRectF MindMapNode::textBoundingRect(QPainter *painter) const
{

    return painter->boundingRect(m_bounds,
                           Qt::TextWordWrap|Qt::TextDontClip,
                           m_text);
}

void MindMapNode::paint(QPainter *painter, qreal x, qreal y)
{
    setPos(x, y);

    m_bounds = textBoundingRect(painter);

    painter->drawText(m_bounds, Qt::TextWordWrap|Qt::TextDontClip,
                  m_text, &m_bounds);

    qreal childX = x + m_bounds.width() + X_MARGIN;

    //Calculate child box height

    qreal cbHeight = 0.0;

    foreach(MindMapNode* child, m_children) {
        cbHeight += child->textBoundingRect(painter).height();
    }

    cbHeight += (m_children.length() - 1) * Y_MARGIN;

    qreal childY = cbHeight / 2.0;

    foreach(MindMapNode* child, m_children) {
        child->paint(painter, childX, childY);
        childY += child->textBoundingRect(painter).height();
        childY += Y_MARGIN;
    }



}

void MindMapNode::setText(const QString &text)
{
    if(m_text == text)
        return;

    m_text = text;
}

MindMapNode* MindMapNode::addChild(QString text)
{
    auto child = new MindMapNode(this);
    child->setText(text);
    m_children.append(child);
    return child;
}

void MindMapNode::setPos(qreal x, qreal y)
{
    m_bounds.setTopLeft(QPointF(x, y));
}
