
#include <iostream>
#include "binaryTree.cpp"
#include <vector>

using namespace std;

void descending(Node *root);
void ascending(Node *root);
void postOrder(Node *root);
bool equal(Node *left, Node *right);
int leafs(Node *root);
int leftMost(Node *root);
int getDepth(Node *root);
bool checkBalanced(Node *root);
bool validate(Node *root, int parent);
bool test(int n);

int main()
{

    BinaryTree left;
    BinaryTree right;
    left.insert(50);
    left.insert(51);
    left.insert(49);
    left.insert(53);
    left.insert(65);
    left.insert(44);

    // left.insert(20);
    // right.insert(15);
    // right.insert(10);
    // right.insert(5);
    // right.insert(2);
    // right.insert(1);

    Node *leftRoot = left.getRoot();
    Node *rightRoot = right.getRoot();

    // Node *l = leftRoot->getLeft();

    // cout << leftMost(leftRoot);
    cout
        << validate(leftRoot, leftRoot->getVal());
    // cout << checkBalanced(leftRoot);
    // descending(leftRoot);
    // postOrder(leftRoot);
    // cout << equal(leftRoot, rightRoot);

    // cout << leafs(root);
    return 0;
}
int leftMost(Node *root)
{
    if (!root->getLeft())
        return root->getVal();
    return root->getVal() + leftMost(root->getLeft());
}
// bool equal(Node *left, Node *right)
// {
//     if (!left && !right)
//         return true;
//     if (left && right)
//         return true + equal(left->getLeft(), right->getRight()) + equal(left->getRight(), right->getRight());
// }
void postOrder(Node *root)
{
    if (!root)
        return;
    else
    {
        postOrder(root->getRight());
        postOrder(root->getLeft());
        cout << root->getVal() << endl;
    }
}
void descending(Node *root)
{
    if (!root)
        return;
    else
    {                                   //  30
        descending(root->getRight());   //-> rightMost Node()        //  20
        cout << root->getVal() << endl; //  12
        descending(root->getLeft());    //  1
    }
}
void ascending(Node *root)
{
    if (!root)
        return;
    else
    {
        ascending(root->getLeft());
        cout << root->getVal() << endl;
        ascending(root->getRight());
    }
}

int leafs(Node *root)
{
    if (!root)
        return 0;
    else
    {
        if (!root->getLeft() && !root->getRight())
            return 1 + leafs(root->getLeft()) + leafs(root->getRight());
        else
            return leafs(root->getLeft()) + leafs(root->getRight());
    }
}

int getDepth(Node *root)
{
    if (!root)
        return 0;
    else
        return 1 + max(getDepth(root->getLeft()), getDepth(root->getRight()));
}

bool checkBalanced(Node *root)
{
    if (!root)
        return true;
    else
    {
        int leftDepth = getDepth(root->getLeft());
        int rightDepth = getDepth(root->getRight());
        cout << "left: " << leftDepth << " right: " << rightDepth << endl;
        return abs(leftDepth - rightDepth) < 2 && checkBalanced(root->getLeft()) && checkBalanced(root->getRight());
    }
}

bool validate(Node *root, int parent)
{
    if (!root)
        return true;
    else
    {
        }
}

// bool test(int n)
// {
//     if (n == 0)
//         return true;
//     if (n > 0)
//         return true && test(n - 1);
// }