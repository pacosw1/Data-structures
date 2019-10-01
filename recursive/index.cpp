#include <iostream>
#include <map>
#include <vector>

using namespace std;
int factorial(int num);
int fib(int num); // 1 1 2 3 5 8 13 21
int fibIterative(int num);
int threeStep(int n);

int main()
{
    cout << factorial(5) << endl;
    cout << fib(4) << endl;
    cout << fibIterative(4) << endl;
    cout << threeStep(3) << endl;
    return 0;
}

int factorial(int num)
{
    if (num == 1)
        return num;
    else
        return num * factorial(num - 1);
}
int fibIterative(int num)
{
    int prev = 0;
    int res = 0;
    for (int i = 1; i < num; i++)
    {
        res = prev + (i - 1);
        prev = res;
    }
    return res;
}

int fib(int num) // 1 1 2 3 5 8 13 21
{
    if (num <= 2)
        return 1;
    else
        return fib(num - 1) + fib(num - 2);
}

int threeStep(int n)
{

    if (n < 2)
        return 1;
    else
        return threeStep(n - 1) + threeStep(n - 2) + threeStep(n - 3);
}

vector<int> mergeSort(vector<int>)
{
}