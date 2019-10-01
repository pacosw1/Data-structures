#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    int id;
    int val;
    vector<Node> nodes;

public:
    Node(int);

    int getId()
    {
        return id;
    }
    void setId(int newId)
    {
        id = newId;
    }
    vector<Node> getConnections()
    {
        return nodes;
    }
};
Node::Node(int value)
{
    this->val = value;
}
class Graph
{
private:
    vector<Node> nodes;

public:
    void addNode(Node newNode)
    {
    }
};