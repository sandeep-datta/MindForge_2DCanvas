#include "mindmapview.h"

MindMapView::MindMapView(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_root(nullptr)
    , m_bMouseDown(false)
    , m_rootCentered(false)
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

    m_root->updateTextBounds(painter);

    if (!m_rootCentered) {
        m_root->moveTo(paintableRect.left(), paintableRect.height()/2);
        m_rootCentered = true;
    }

    m_root->paint(painter);
}

void MindMapView::setRootNode(MindMapNode *root)
{
    m_root = root;
    m_rootCentered = false;
    update();
}

void MindMapView::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    m_bMouseDown = true;
    m_lastPos = event->localPos();
}

void MindMapView::mouseReleaseEvent(QMouseEvent *)
{
    m_bMouseDown = false;
}

void MindMapView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMouseDown) {
        event->accept();
        QPointF pos = event->localPos();
        m_root->translate(pos - m_lastPos);
        m_lastPos = pos;
        update();
    }
}

void MindMapView::wheelEvent(QWheelEvent *event)
{
    event->accept();
    qDebug() << "wheelEvent" << event->angleDelta();
}
