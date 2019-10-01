#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Route
{
    int origin;
    int destination;
    vector<int> path;
    int cost;
    int stops;

    Route(){};
    Route(int o, int d, int c)
    {
        origin = o;
        cost = c;
        destination = d;
        stops = 0;
    }

    void addStop(int city)
    {
        path->push_back(city);
        stops += 1;
    }
};

// struct Database
// {
//     vector<string> cities;
//     vector<Route *> *flights;

//     Database(vector<string> c)
//     {
//         cities = c;
//     }

//     void addRoute(Route *route)
//     {
//         flights->push_back(route);
//     }

//     void add(int origin, int destination, int cost)
//     {
//         addRoute(new Route(origin, destination, cost));
//     }

//     void update(int origin, int destination, int cost, int city)
//     {
//         for (int i = 0; i < flights->size(); i++)
//         {
//             Route *curr = flights->at(i);

//             if (curr->origin == origin && curr->destination == destination)
//             {
//                 curr->addStop(city);

//                 cout << "UPDATE"
//                      << "stops: " << curr->stops;
//             }
//         }
//     }

//     vector<Route *> routesWithStops(int stops)
//     {
//         vector<Route *> res;
//         for (int i = 0; i < flights->size(); i++)
//         {
//             Route *curr = flights->at(i);
//             if (curr->stops == stops)
//                 res.push_back(curr);
//         }
//         return res;
//     }

//     vector<Route *> destinations(int origin)
//     {
//         vector<Route *> res;
//         for (int i = 0; i < flights->size(); i++)
//         {
//             Route *curr = flights->at(i);
//             if (curr->origin == origin)
//                 res.push_back(curr);
//         }
//         return res;
//     }
//     void findAndUpdate(int origin, int destination, int stop)
//     {
//         Route *curr;
//         for (int i = 0; i < flights->size(); i++)
//         {
//             curr = flights->at(i);
//             if (curr->origin == origin && curr->destination == destination)
//             {
//                 break;
//             }
//         }
//         curr->path->push_back(stop);
//         curr->stops += 1;
//     }
//     vector<Route *> routes(int origin, int destination)
//     {
//         vector<Route *> res;
//         for (int i = 0; i < flights->size(); i++)
//         {
//             Route *curr = flights->at(i);
//             if (curr->origin == origin && curr->destination == destination)
//                 res.push_back(curr);
//         }
//         return res;
//     }
// };
