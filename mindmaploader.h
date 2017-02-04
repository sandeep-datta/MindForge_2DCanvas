#ifndef MINDMAPLOADER_H
#define MINDMAPLOADER_H

#include "mindmapnode.h"

class MindMapLoader
{
public:
    MindMapLoader();
    static MindMapNode* load();
};

#endif // MINDMAPLOADER_H
