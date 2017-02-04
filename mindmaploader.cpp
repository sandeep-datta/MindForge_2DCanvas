#include "mindmaploader.h"

MindMapLoader::MindMapLoader()
{

}

MindMapNode *MindMapLoader::load()
{
    auto root = new MindMapNode(nullptr);

    root->setText("Root node.");

    auto first = new MindMapNode(root);
    first->setText("First child node.");

    auto second = new MindMapNode(root);
    second->setText("Second child node.");

    auto third = new MindMapNode(root);
    third->setText("Third child node.");

    auto firstGrand = new MindMapNode(first);
    firstGrand->setText("First grand child node.");

    return root;
}
