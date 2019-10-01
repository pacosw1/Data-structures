#include <iostream>
#include <vector>

using namespace std;

class Flight
{
public:
    string origin;
    string target;
    int cost;

    Flight(string o, string t, int c)
    {
        origin = o;
        target = t;
        cost = c;
    }
};
