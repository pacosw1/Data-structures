#include <stdio.h>
#include "LinkedList.cpp"
using namespace std;

struct TenHash
{
    LinkedList *hash[10];
    TenHash()
    {
        init();
    }

    void init()
    {
        for (int i = 0; i < 10; i++)
            hash[i] = new LinkedList();
    }
    int maxCount()
    {
        int maxVal = 0;   //can be 0 since min Val = 1
        int maxCount = 0; // -------------^

        Node *curr;
        for (int i = 0; i < 10; i++) //O(n) Max checks will be N in worst case
        {
            curr = hash[i]->getHead(); //update Linked List
            while (curr)               //while values in list
            {
                if (curr->count > maxCount) //update max val if maxCount found
                {
                    maxCount = curr->count;
                    maxVal = curr->val;
                }
                curr = curr->next; //keep going
            }
        }
        return maxVal;
    }

    void add(int val)
    {
        int index = getIndex(val);               //get index to place value
        Node *result = hash[index]->lookUp(val); //check if value exists
        if (!result)                             //if not, add it
            hash[index]->insert(val);
        else
            result->add(1); //else, add 1 to its count var;
    }
    int getIndex(int val) //hash function to choose a location;
    {
        return (val % 10) % 10; //val % 10 returns last digit
    }
};

int main()
{
    TenHash hash;
    int data[10] = {1, 3, 4, 2, 1, 3, 9, 9, 9, 9};
    for (int i = 0; i < 10; i++)
    {
        hash.add(data[i]);
    }
    cout << hash.maxCount();

    // cout << list.maxCount();

    // cout << "max: " << hash.maxReps();
    return 0;
}

//fibonacci

// 0, 1    (n-2) + (n-1)