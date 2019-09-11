#include <iostream>
#include <fstream>
using namespace std;

class CSVStream
{

public:
    string value;
    ifstream file;

    int getVal()
    {
        return stoi(value);
    }
    bool nextVal()
    {

        if (getline(file, value, '\n'))
        {
            return true;
        }
        closeFile();
        return false;
    }
    void openFile(string path)
    {
        file.open(path);
    }

    void closeFile()
    {
        file.close();
    }
};
