#include <iostream>
class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }

    bool findNode(int val)
    {
        Node *left;
        Node *right;
        Node *curr = root;
        while (curr->left || curr->right)
        {
            if (curr->left->val == val)
                return 1;
            else if (curr->right->val == val)
                return 1;
            else
            {
                if (curr->right)
                    right = curr->right;
                if (curr->left)
                    left = curr->left;
            }
        }
        return 0;
    }

    void printRoot()
    {
        Node *curr = root;
        Node *left;
        Node *right;
        while (curr->left || curr->right)
        {
            std::cout << "curr: " << curr->val;
            if (curr->left)
            {
                std::cout << "left: " << curr->left->val;
                left = curr->left;
            }
            if (curr->right)
            {
                std::cout << "right: " << curr->right->val;
                right = curr->right;
            }
        }
    }
    void addNode(int val)
    {
        if (!root)
        {
            root = new Node(val);
            return;
        }

        Node *curr = root;
        while (curr->left || curr->right)
        {
            if (val < curr->val)
            {
                if (curr->left)
                    curr = curr->left;
                else
                    curr->left = new Node(val);
            }
            else if (val >= curr->val)
            {
                if (curr->right)
                    curr = curr->right;
                else
                    curr->right = new Node(val);
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.printRoot();
    return 0;
}