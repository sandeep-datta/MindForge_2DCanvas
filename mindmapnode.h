#ifndef MMNODE_H
#define MMNODE_H

#include <QObject>
#include <QList>
#include <QPainter>

class MindMapNode : public QObject
{
    Q_OBJECT
public: //Constants
    const qreal MAX_WIDTH = 100.0;
    const qreal X_MARGIN = 30.0;
    const qreal Y_MARGIN = 30.0;

public:
    explicit MindMapNode(QObject *parent = 0);
    QRectF textBoundingRect(QPainter *painter);
    qreal subTreeYSize(QPainter *painter);
    void paint(QPainter *painter);
    void setText(const QString &text);
    void setColor(QColor color);
    void moveTo(qreal x, qreal y);
    MindMapNode *addChild(QString text, QColor color=Qt::black);

signals:

public slots:

private: //Methods
    //None so far

private: //Variables
    QString             m_text;
    QList<MindMapNode*> m_children;
    QRectF              m_bounds;
    QColor              m_color;
    bool                m_updateTextBoundingRect;
};

#endif // MMNODE_H
