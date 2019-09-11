#include <iostream>
#include <fstream>
#include <vector>
#include "../hash/HashTable.cpp"
#include "./CSVStream.cpp"

#include <list>
using namespace std;

//reading to files
int solutionOne(string path);   //speed N + 100 ---> O(n) memory O(1) (O(1) add) 0 comparisons. optimized for speed  *winner
int solutionTwo(string path);   //  O(n)log(n)   memory O(n)
int solutionThree(string path); //speed O(n) memory O(1) O(1) add --> worst 10 comparison`s      optimized for memory (sometimes)

int main()
{
    int s1 = solutionOne("./data/calif1.txt");
    int s2 = solutionTwo("./data/calif1.txt");
    int s3 = solutionThree("./data/calif1.txt");
    cout << "S1: " << s1 << " S2: " << s2 << " s3: " << s3;
    return 0;
}

int solutionOne(string path) //speed N + 100 ---> O(n) memory O(1);
{
    CSVStream data; //load data processing class
    data.openFile(path);

    int val = 0, bestReps = 0, bestGrade = 0; //init final count vars
    int frequency[100];

    while (data.nextVal()) //fill out array with reps at each index
    {
        val = data.getVal(); //read values from .txt file one by one

        frequency[val - 1]++; //-1 to fit it into a 0-99 index array
    }

    for (int i = 0; i < 100; i++) //perform final count
    {
        if (frequency[i] >= bestReps) //>= ensures greatest value is returned if tied
        {
            bestReps = frequency[i];
            bestGrade = (i + 1); //add 1 to show actual value
        }
    }
    return bestGrade;
}

int solutionTwo(string path) // 2n + log(n) -----> O(n)
{
    CSVStream data;
    data.openFile(path);
    vector<int> grades;
    int count = 0;
    while (data.nextVal()) //fill vector
    {
        grades.push_back(data.getVal());
    }

    sort(grades.begin(), grades.end()); //sort vector

    int bestVal = 0, currVal = grades[0];
    int bestCount = 0, currCount = 0;

    for (int i = 0; i < grades.size(); i++) //111122233333333
    {
        if (grades[i] == currVal) //if same value add to current count
            currCount++;
        else //if new value (sorted means no more past vals)
        {
            if (currCount >= bestCount) // if current Val count > best update bestCount and bestVal
            {
                bestCount = currCount;
                bestVal = currVal;
            }
            currVal = grades[i]; //move to next value in vector
            currCount = 0;
        }
        if (currCount >= bestCount) // check again to cover edge cases, only one unique value, check last value
        {
            bestCount = currCount;
            bestVal = currVal;
        }
    }
    return bestVal;
}

int solutionThree(string path)
{
    CSVStream data; //load data processing class
    data.openFile(path);

    HashTable hash;

    while (data.nextVal()) //fill out array with reps at each index
    {
        hash.add(data.getVal());
    }
    return hash.mostCommon();
}