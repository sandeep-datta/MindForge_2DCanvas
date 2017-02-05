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
//    QPainterPath path;
//    path.addRect(20, 20, 60, 60);

//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);

//    painter->fillRect(contentsBoundingRect(), Qt::white);

//    painter->setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
//                        Qt::FlatCap, Qt::MiterJoin));
//    painter->setBrush(QColor(122, 163, 39));

//    painter->drawPath(path);
    QRectF paintableRect = contentsBoundingRect();

    if (!m_root) {
        painter->fillRect(paintableRect, Qt::gray);
        return;
    }

    painter->fillRect(paintableRect, Qt::white);

    qreal y = (paintableRect.height() -
               m_root->textBoundingRect(painter).height())/2;

    //m_root->setPos(paintableRect.left(), y);

    m_root->paint(painter, 0.0, y);
}

void MindMapView::setRootNode(MindMapNode *root)
{
    m_root = root;
    update();
}
