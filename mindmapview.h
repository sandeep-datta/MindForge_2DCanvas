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
    MindMapNode *m_root;
};

#endif // MINDMAPWIDGET_H
