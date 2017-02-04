#ifndef MINDMAPWIDGET_H
#define MINDMAPWIDGET_H

#include <QtQuick>
#include "mmnode.h"

class MindMapView : public QQuickPaintedItem
{
    Q_OBJECT

public:
    MindMapView(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);

private:
    MmNode *m_root;
};

#endif // MINDMAPWIDGET_H
