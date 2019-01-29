#include <iostream>
using namespace std;
//my implementation of a Queue List
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

struct Queue
{

  private:
    Node *head; //start of the queue
    Node *tail; //end of the queue
  public:
    Queue()
    {
        head = NULL;
        tail = NULL;
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
            tail = head;
        }
    }
    //insert value in the front
    void queue(int val)
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
    { //check first in line
        return tail->val;
    }
    //removes the last node
    void deQueue()
    {
        if (head)
        {
            Node *curr = head;
            Node *prev = head;
            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }                  // will get second to last node
            prev->next = NULL; //delete the tail (last node)
            tail = prev;
        }
    }
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
    //end of Queue
};

int main()
{

    //try it
    Queue list;
    list.queue(1);
    list.queue(2);
    list.queue(3);
    list.queue(4);
    list.deQueue();
    list.deQueue();
    list.print();
    /*methods
    print()

    lookup(int val)
    queue(int val)
    dequeue(int val)
    peek(int val)
  */
}