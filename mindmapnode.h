#ifndef MMNODE_H
#define MMNODE_H

#include <QObject>
#include <QList>
#include <QPainter>

class MindMapNode : public QObject
{
    Q_OBJECT
public:
    explicit MindMapNode(QObject *parent = 0);
    const QRectF *boundingRect() const;
    void paint(QPainter *painter);
    void setText(const QString &text);
    const qreal MAX_WIDTH = 600.0;
    void setPos(const QPointF& pos);

signals:

public slots:

private: //Methods
    //None so far

private: //Variables
    QString m_text;
    QList<MindMapNode> m_children;
    QRectF m_bounds;
    bool   m_boundsValid;

};

#endif // MMNODE_H