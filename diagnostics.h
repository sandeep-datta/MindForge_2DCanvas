#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <QDebug>

extern int g_indents;

void indent();

#define ENTER() { \
    indent(); \
    qDebug()<< "Entering: " << __FUNCTION__ << endl; \
    g_indents++; \
}

#define EXIT() { \
    g_indents--; \
    indent(); \
    qDebug()<< "Exiting: " << __FUNCTION__ << endl; \
}

#define TRACE(X) { \
    indent(); \
    qDebug() << __LINE__ << ":" << #X << "=" << (X) << endl; \
}

class diagnostics
{
public:
    diagnostics();
};

#endif // DIAGNOSTICS_H
