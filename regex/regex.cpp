#include <iostream>
#include <regex>

using namespace std;

bool isPalindrome(string input);

int toLower(int character);
int main()
{

    cout << isPalindrome("1Bjb1");
    return 0;
}

int toLower(int character)
{
    if (character < 97 && character >= 65)
        return character + 32;
    else
        return character;
}

bool isPalindrome(string input)
{
    regex match("[^A-Za-z0-9]");
    string result = regex_replace(input, match, "");

    int start = 0, end = result.length() - 1;

    while (start < end)
    {
        cout << "left: " << toLower(result[start]) << " right: " << toLower(result[end]) << endl;
        if (toLower(result[start]) != tolower(result[end]))
            return false;

        start++;
        end--;
    }
    return true;
}