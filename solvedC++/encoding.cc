#include <iostream>
#include <cmath>
using namespace std;

string encryption(string s)
{
    int length = 0;
    string rs, result;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] != ' ')
        {
            rs.push_back(s[i]);
            length++;
        }
    }

    float ref = sqrt(length);
    int column = ceil(ref);

    for (int j = 0; j < column; j++)
    {
        for (int i = j; i<length; i += column)
        {
            result.push_back(rs[i]);
        }
        result.push_back(' ');
    }

    return result;
}

int main()
{
    cout<<encryption("if man was meant to stay on the ground god would have given us roots");
    return 0;
}