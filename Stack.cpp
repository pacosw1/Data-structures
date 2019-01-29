#include <iostream>
using namespace std;
//my implementation of a singely Linked List
struct Node
{
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

struct Stack
{
  private:
    Node *head; //start of the list
  public:
    Stack()
    {
        head = NULL;
    }

    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }

    //if list is empty insert in head (front)
    void insertEmpty(int val)
    {
        Node *curr = head;
        if (!curr)
        {
            head = new Node(val);
        }
    }
    //insert value in the front
    void push(int val)
    {
        Node *curr = head;
        if (!curr)
            insertEmpty(val);
        else
        { // newNode  >>  head -> next -> next
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
    }
    int peek()
    {
        return head->val;
    }
    //removes the first node
    void pop()
    {
        if (head)
        { //make sure there is something to delete;
            Node *curr = head;
            head = curr->next;
            curr = NULL;
        }
    }
    //removes inbetween nodes

    //search for a value in nodes
    Node *lookUp(int val)
    {
        Node *curr = head;
        while (curr)
        { //while node is not null keep looking
            if (curr->val == val)
                return curr;
            else
                curr = curr->next;
        }
        return NULL;
    }
    //end of stack
};

int main()
{
    //try it
    Stack list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.pop();
    list.print();
    /*methods
  
    print()
    lookup(int val)
    push(int val)
    peek(int val)
    pop(int val)
   
  */
}