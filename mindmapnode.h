#ifndef MMNODE_H
#define MMNODE_H

#include <QObject>
#include <QList>
#include <QPainter>

class MindMapNode : public QObject
{
    Q_OBJECT
public: //Constants
    const qreal MAX_WIDTH = 300.0;
    const qreal X_MARGIN = 30.0;
    const qreal Y_MARGIN = 30.0;

public:
    explicit MindMapNode(QObject *parent = 0);
    const QRectF textBoundingRect(QPainter *painter) const;
    void paint(QPainter *painter, qreal x, qreal y);
    void setText(const QString &text);
    MindMapNode *addChild(QString text);
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
