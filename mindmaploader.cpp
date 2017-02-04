#include "mindmaploader.h"

MindMapLoader::MindMapLoader()
{

}

MindMapNode *MindMapLoader::load()
{
    auto mmn = new MindMapNode(nullptr);

    mmn->setText("Root node.");

    return mmn;
}
