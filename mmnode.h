#ifndef MMNODE_H
#define MMNODE_H

#include <QObject>

class MmNode : public QObject
{
    Q_OBJECT
public:
    explicit MmNode(QObject *parent = 0);


signals:

public slots:

private:
    QString m_text;
};

#endif // MMNODE_H
