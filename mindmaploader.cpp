#include "mindmaploader.h"

MindMapLoader::MindMapLoader()
{

}

//MindMapNode *MindMapLoader::load()
//{
//    auto root = new MindMapNode(nullptr);
//    root->setText("Root node.");

//    root->addChild("First child node.", Qt::red);

//    root->addChild("Second child node.", Qt::green);

//    return root;
//}

//MindMapNode *MindMapLoader::load()
//{
//    auto root = new MindMapNode(nullptr);
//    root->setText("Root node.");

//    auto first = root->addChild("First child node.");

//    first->addChild("First grand child node.");

//    first->addChild("Second grand child node.");

//    return root;
//}


MindMapNode *MindMapLoader::load()
{
    auto root = new MindMapNode(nullptr);
    root->setText("Root node.");

    auto first = root->addChild("First child node.");

    auto second = root->addChild("Second child node.");

//    root->addChild("Third child node.");

    first->addChild("First grand child node.");

    first->addChild("Second grand child node.");

    second->addChild("Third grand child node.");

    second->addChild("Fourth grand child node.");

    return root;
}
