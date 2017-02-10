#include "mindmapview.h"

MindMapView::MindMapView(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_root(nullptr)
{
    setAntialiasing(true);
    setOpaquePainting(true);
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
    m_root->moveTo(paintableRect.left(), paintableRect.height()/2);
    m_root->paint(painter);
}

void MindMapView::setRootNode(MindMapNode *root)
{
    m_root = root;
    update();
}
