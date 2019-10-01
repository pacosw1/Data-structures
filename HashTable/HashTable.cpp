#include <iostream>
#include <list>

using namespace std;

struct Node
{

    int val;
    int count;

    Node(int x)
    {
        val = x;
        count = 1;
    }
}; /// array[0] List ( {val: 100, count: 4}, )

class HashTable
{
public:
    // private:
    list<Node> hash[10];

    int mostCommon()
    {

        int bestCount = 0;
        int bestGrade = 0;
        for (int i = 0; i < 10; i++)
        {
            cout << "hash[" << i << "]: ";
            for (list<Node>::iterator curr = hash[i].begin(); curr != hash[i].end(); ++curr)
            {
                cout << "( val: " << curr->val << " count: " << curr->count << ") -> ";
                if (curr->count > bestCount)
                {
                    bestCount = curr->count;
                    bestGrade = curr->val;
                }
                else if (curr->count == bestCount && curr->val > bestGrade)
                    bestGrade = curr->val;
            }
            cout << endl;
        }
        return bestGrade;
    }
    void add(int val)
    {
        int hashIndex = getIndex(val);
        list<Node> &toBeSearched = hash[hashIndex];

        for (list<Node>::iterator curr = toBeSearched.begin(); curr != toBeSearched.end(); ++curr)
        {
            if (curr->val == val)
            {
                curr->count++;
                return;
            }
        }
        toBeSearched.push_back(*new Node(val));
    }
    // void add(int val)
    // {
    //     int index = getIndex(val);            //get index to place value
    //     list *result = hash[index].find(1); ) //check if value exists
    //     //                if (!result)       //if not, add it
    //     //                hash[index]
    //     //                    ->insert(val);
    //     // else result->add(1); //else, add 1 to its count var;
    // }

    int getIndex(int val) //hash function to choose a location;
    {
        return (val % 10) % 10; //val % 10 returns last digit
    }
};
