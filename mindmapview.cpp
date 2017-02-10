#include "mindmapview.h"

MindMapView::MindMapView(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_root(nullptr)
    , m_bMouseDown(false)
{
    setAntialiasing(true);
    setOpaquePainting(true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void MindMapView::paint(QPainter *painter)
{
    QRectF paintableRect = contentsBoundingRect();

    if (!m_root) {
        painter->fillRect(paintableRect, Qt::gray);
        return;
    }

    painter->fillRect(paintableRect, Qt::white);

    qreal y = (paintableRect.height() -
               m_root->textBoundingRect(painter).height())/2;

    m_root->moveTo(paintableRect.left(), y);
    m_root->paint(painter);
}

void MindMapView::setRootNode(MindMapNode *root)
{
    m_root = root;
    update();
}

void MindMapView::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    m_bMouseDown = true;
    m_clickPos = event->localPos();
    //qDebug() << "mousePressEvent" << pos.x() << pos.y();
}

void MindMapView::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMouseDown = false;

    //qDebug() << "mouseReleaseEvent" << pos.x() << pos.y();
}

void MindMapView::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();
    QPointF pos = event->localPos();
    //TODO: move the root node.
    //qDebug() << "mouseMoveEvent" << pos.x() << pos.y();
}

void MindMapView::wheelEvent(QWheelEvent *event)
{
    event->accept();
    qDebug() << "wheelEvent" << event->angleDelta();
}
