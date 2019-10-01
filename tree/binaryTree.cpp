#include <iostream>
using namespace std;
class Node
{
private:
    Node *left;
    Node *right;
    int val;

public:
    Node(int);
    Node *getLeft()
    {
        return left;
    }
    int getVal()
    {
        return val;
    }
    Node *getRight()
    {
        return right;
    }
    void setRight(int val)
    {
        right = new Node(val);
    }
    void setLeft(int val)
    {
        left = new Node(val);
    }
};

Node::Node(int value)
{
    this->val = value;
    this->left = nullptr;
    this->right = nullptr;
}

class BinaryTree
{
private:
    Node *root;

public:
    Node *getRoot()
    {
        return root;
    }
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int val) //add node
    {

        Node *curr = root;
        insertR(root, val);

        // //loop
        // if (val > root->val) root = root->right;
    }
    void insertR(Node *curr, int val) //get Node
    {
        if (!root)
            root = new Node(val);
        else
        {
            if (val < curr->getVal())
            {
                if (!curr->getLeft())
                    return curr->setLeft(val);
                insertR(curr->getLeft(), val);
            }
            else
            {
                if (!curr->getRight())
                    return curr->setRight(val);
                insertR(curr->getRight(), val);
            }
        }
    }

    bool find(Node *curr) //find node
    {
        return true;
    }

    void remove(Node *curr)
    {
    }
};
