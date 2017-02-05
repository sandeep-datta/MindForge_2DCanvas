#include "mindmaploader.h"

MindMapLoader::MindMapLoader()
{

}

MindMapNode *MindMapLoader::load()
{
    auto root = new MindMapNode(nullptr);
    root->setText("Root node.");

    auto first = root->addChild("First child node.");

    root->addChild("Second child node.");

    root->addChild("Third child node.");

    first->addChild("First grand child node.");

    first->addChild("Second grand child node.");

    return root;
}
