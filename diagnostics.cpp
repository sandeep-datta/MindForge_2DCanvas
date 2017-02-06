#include "diagnostics.h"

int g_indents = 0;

void indent() {
    for (int i = 0; i < g_indents; i++) {
       qDebug("%s", "    ");
    }
}

diagnostics::diagnostics()
{

}
