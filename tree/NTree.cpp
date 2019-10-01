#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    vector<Node *> children;
    int val;

    void add(int val)
    {
        children.push_back(new Node(val));
    }
    Node(int val)
    {
        this->val = val;
    }
};
void print(Node *root);

int main()
{
    Node *root = new Node(1);
    root->add(2);
    root->add(3);
    root->add(4);
    print(root);
    // cout << root->children.at(0)->val;
    return 0;
}

void print(Node *root)
{
    if (root->children.size() < 1)
        cout << root->val << endl;
    else
    {
        cout << root->val;
        for (int i = 0; i < root->children.size(); i++)
        {
            print(root->children.at(i));
        }
        cout << endl;
    }
}