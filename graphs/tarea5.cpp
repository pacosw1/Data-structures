#include <iostream>
#include "../Files/CSVStream.cpp"
#include "Flight.cpp"
#include <vector>
#include <map>
using namespace std;
#define INF 999;

//predeclare functions
Flight parseFlight(string source);                                                                                                   //turns flight data into structured object
vector<vector<int> /**/> loadData(string file, map<string, int> &cities, vector<string> &cityNames);                                 //loads data into memory
void printSolution(vector<vector<int> /**/> &dist);                                                                                  //prints shortest path 2d vector
void floydWarshall(vector<vector<int> /**/> &costs, vector<vector<int> /**/> &stops, vector<vector<vector<int> /**/> /**/> &routes); //finds shortest route
int totalCities(string file);                                                                                                        //finds 2d vector's dimensions
void route(int origin, int destination, vector<vector<int> /**/> costs, vector<vector<int> /**/> stops, vector<vector<vector<int> /**/> /**/> routes, vector<string> cities);
void printRoute(vector<int> route, vector<string> cities); //prints specified route
void destinations(int origin, vector<vector<int> /**/> &costs, vector<vector<int> /**/> &stops, vector<vector<vector<int> /**/> /**/> &routes, vector<string> &cities);

int main()
{

    int size = totalCities("test.txt"); //find dimensions for storage

    map<string, int> cities; // map used to facilitate loadind data;

    vector<string> cityNames;                                                                           // vector with city names with index
    vector<vector<int> /**/> costs(size, vector<int>(size));                                            //shortest path storage
    vector<vector<int> /**/> stops(size, vector<int>(size));                                            //number of stops storage
    vector<vector<vector<int> /**/> /**/> routes(size, vector<vector<int> /**/>(size, vector<int>(0))); // routes for each flight storage

    costs = loadData("test.txt", cities, cityNames); //loads data int vectors

    floydWarshall(costs, stops, routes); //generates optimal path, counts stops

    //print solution and stops vectord
    printSolution(costs);
    printSolution(stops);

    //find specific flight info
    route(4, 3, costs, stops, routes, cityNames);

    //find all outsanding flights given an origin
    destinations(4, costs, stops, routes, cityNames);

    return 0;
}

//utility functions

void route(int origin, int destination, vector<vector<int> /**/> costs, vector<vector<int> /**/> stops, vector<vector<vector<int> /**/> /**/> routes, vector<string> cities)
{
    int cost = costs[origin][destination];
    int allStops = stops[origin][destination];
    vector<int> route = routes[origin][destination];

    cout << "Flight: " << cities[origin] << " --> " << cities[destination] << endl;
    cout << "Stops: " << route.size() << endl;
    cout << "Full Route: " << endl;
    cout << cities[origin] << " --> ";

    for (int i = 0; i < route.size(); i++)
    {
        cout << cities[route[i]] << " --> ";
    }
    cout << cities[destination];
}
void destinations(int origin, vector<vector<int> /**/> &costs, vector<vector<int> /**/> &stops, vector<vector<vector<int> /**/> /**/> &routes, vector<string> &cities)
{
    cout << "Origin: " << cities[origin] << endl;
    cout << "All Flights: " << endl
         << endl;
    for (int i = 0; i < cities.size(); i++)
    {

        if (i != origin && costs[origin][i] != 999)
        {
            cout << "Destination: "
                 << cities[i] << endl
                 << "Price: " << costs[origin][i] << endl;
            if (routes[origin][i].size() > 0)
            {
                cout << cities[origin] << " --> ";
                printRoute(routes[origin][i], cities);
                cout << cities[i];
            }

            else
                cout << "Direct Flight";
            cout << endl
                 << endl;
        }
    }
}

void printRoute(vector<int> route, vector<string> cities)
{
    for (int i = 0; i < route.size(); i++)
    {
        cout << cities[route[i]] << " --> ";
    }
}
void allDestinations(int origin, map<string, int> cities, vector<vector<int> /**/> costs, vector<string> cityNames, vector<vector<int> /**/> &stops)
{
    string originName = cityNames[origin];
    for (int j = 0; j < cities.size(); j++)
    {
        if (costs[origin][j] != 999 && origin != j)
            cout << "from " << originName << " to " << cityNames.at(j) << " price: " << costs[origin][j] << " stops: " << stops[origin][j] << endl;
    }
}

vector<vector<int> /**/> loadData(string file, map<string, int> &cities, vector<string> &cityNames)
{
    int count = 0;
    CSVStream stream;

    stream.openFile(file);

    while (stream.nextVal())
    {
        string curr = stream.getRawVal();
        if (curr == "#")
            break;
        else
        {
            cities[curr] = count;
            cityNames.push_back(curr);
        }
        count++;
    }
    vector<vector<int> /**/
           >
    costs(cities.size(), vector<int>(cities.size()));

    while (stream.nextVal())
    {

        string flightData = stream.getRawVal();
        Flight currFlight = parseFlight(flightData);
        costs[cities[currFlight.origin]][cities[currFlight.target]] = currFlight.cost;
    }

    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities.size(); j++)
        {
            if (i == j)
                costs[i][j] = 0;
            else if (costs[i][j] == 0)
            {
                costs[i][j] = INF;
            }
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }
    return costs;
}

Flight parseFlight(string source)
{
    vector<string> data;

    string token;
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] == ' ' || source[i] == '\n')
        {
            data.push_back(token);
            token = "";
        }
        else
            token += source[i];
    }

    return Flight(data.at(0), data.at(1), stoi(token));
}

void printSolution(vector<vector<int> /**/> &dist)
{
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
        {
            if (dist[i][j] == 999)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int> /**/> &costs, vector<vector<int> /**/> &stops, vector<vector<vector<int> /**/> /**/> &routes)
{
    int size = costs.size();
    vector<vector<int> /**/> dist(costs.size(), vector<int>(costs.size()));

    int i, j, k;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            dist[i][j] = costs[i][j];

    for (k = 0; k < size; k++)
    {
        // Pick all sizeertices as source one by one
        for (i = 0; i < size; i++)
        {
            // Pick all sizeertices as destination for the
            // abosizee picked source
            for (j = 0; j < size; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    stops[i][j] += 1;
                    dist[i][j] = dist[i][k] + dist[k][j];
                    routes[i][j].push_back(k);
                }
            }
        }
    }

    // Print the shortest distance matrix
    costs = dist;
}

int totalCities(string file)
{
    CSVStream stream;
    stream.openFile(file);
    int count = 0;
    while (stream.nextVal())
    {
        string curr = stream.getRawVal();
        if (curr == "#")
            break;
        else
            count++;
    }
    return count;
}
