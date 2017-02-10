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

    if (m_rootCentered) {
        m_root->moveTo(paintableRect.left(), paintableRect.height()/2);
        m_rootCentered = true;
    }
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
    //qDebug() << "mousePressEvent" << m_clickPos.x() << m_clickPos.y();
}

void MindMapView::mouseReleaseEvent(QMouseEvent *)
{
    m_bMouseDown = false;

    //qDebug() << "mouseReleaseEvent";
}

void MindMapView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMouseDown) {
        event->accept();
        QPointF pos = event->localPos();
        //m_root->translate(m_clickPos - pos);
        m_root->translate(pos - m_clickPos);
        m_clickPos = pos;
        update();
        //qDebug() << "mouseMoveEvent" << pos.x() << pos.y() << (m_clickPos - pos);
        //qDebug() << "mouseMoveEvent" << pos.x() << pos.y() << (pos - m_clickPos);

    }
}

void MindMapView::wheelEvent(QWheelEvent *event)
{
    event->accept();
    qDebug() << "wheelEvent" << event->angleDelta();
}
