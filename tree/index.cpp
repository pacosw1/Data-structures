
#include <iostream>
#include "../binaryTree.cpp"

using namespace std;

Node *descending(Node *root);
Node *ascending(Node *root);

int main()
{
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(100);
    tree.insert(20);
    tree.insert(65);
    tree.insert(12);
    tree.insert(1);
    tree.insert(99);

    Node *root = tree.getRoot();

    ascending(root);
    descending(root);
    return 0;
}

Node *descending(Node *root)
{
    if (!root)
        return root;
    else
    {
        descending(root->getRight());
        cout << root->getVal() << endl;
        descending(root->getLeft());
    }
}
Node *ascending(Node *root)
{
    if (!root)
        return root;
    else
    {
        ascending(root->getLeft());
        cout << root->getVal() << endl;
        ascending(root->getRight());
    }
}