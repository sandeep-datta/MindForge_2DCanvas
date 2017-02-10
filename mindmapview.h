#ifndef MINDMAPWIDGET_H
#define MINDMAPWIDGET_H

#include <QtQuick>
#include "mindmapnode.h"

class MindMapView : public QQuickPaintedItem
{
    Q_OBJECT

public:
    MindMapView(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);
    void setRootNode(MindMapNode *root);

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    MindMapNode *m_root;
    bool m_bMouseDown;
    QPointF m_lastPos;
    QPointF m_rootNodePos;
    bool m_rootCentered;
};

#endif // MINDMAPWIDGET_H
