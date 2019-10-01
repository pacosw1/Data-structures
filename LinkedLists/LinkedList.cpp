#include <iostream>
using namespace std;
//my implementation of a singely Linked List
struct Node
{

    int val;
    int count;
    Node *next;

    Node(int x)
    {
        val = x;
        count = 1;
        next = NULL;
    }

    void add(int val)
    {
        count += 1;
    }
};

class LinkedList
{

private:
    Node *tail; //end of the list
    Node *head; //start of the list

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    Node *getHead()
    {
        return head;
    }
    int maxCount(int maxCount) //get Node val with max count
    {
        Node *curr = head;      //dont use actual root
        int maxVal = curr->val; //init
        curr = curr->next;
        while (curr) //while values in list
        {
            if (curr->count > maxCount) //update max val if maxCount found
            {
                maxCount = curr->count;
                maxVal = curr->val;
            }
            curr = curr->next; //keep going
        }
        return maxVal;
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
    void insertFront(int val)
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
    //insert value in between list
    void insertBetween(int locVal, int val)
    {
        Node *curr = lookUp(locVal);
        // curr -> next -> next
        //insert ^
        Node *newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }
    //insert at the back (default)
    void insert(int val)
    { //by defualt this method will add to end
        Node *curr = head;
        if (!curr)
            insertEmpty(val);
        else
        { //head ->next -> tail << newNode
            Node *newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
        }
    }
    //removes the last node
    void removeEnd()
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
    //removes the first node
    void removeFront()
    {
        if (head)
        { //make sure there is something to delete;
            Node *curr = head;
            head = curr->next;
            curr = NULL;
        }
    }
    //removes inbetween nodes
    void removeBetween(int val)
    { //head -> next ->next
        Node *curr = head;
        Node *prev = head; //^remove
        while (curr)
        {
            if (curr->val == val)
                break;
            else
                curr = curr->next;
        }
        if (curr)
        { //if value was found
            prev->next = curr->next;
            curr = NULL;
        }
    }

    void remove(int val)
    {                         //implement all other remove functions
        if (val == head->val) //if at front
            removeFront();
        else if (val == tail->val) // if at end
            removeEnd();
        else
            removeBetween(val); // if in between
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
    //end of LinkedList
};

// int main()
// {

//     //try it
//     LinkedList list;
//     list.insert(20);
//     list.print();
//     /*methods
//     print()

//     lookup(int val)

//     insertFront(int val)
//     insertBack(int val)
//     insertBewtween(int val)

//     removeFront(int val)
//     removeBack(int val)
//     removeBetween(int val)
//     remove(int val)
//       uses all others depending on the location of int val
//   */
// }