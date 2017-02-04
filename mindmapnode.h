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
    const QRectF boundingRect(QPainter *painter) const;
    void paint(QPainter *painter);
    void setText(const QString &text);
    void addChild(MindMapNode *child);
    const qreal MAX_WIDTH = 300.0;
    void setPos(qreal x, qreal y);

signals:

public slots:

private: //Methods
    //None so far

private: //Variables
    QString m_text;
    QList<MindMapNode*> m_children;
    QRectF m_bounds;
};

#endif // MMNODE_H
