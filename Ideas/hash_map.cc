#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

#define word pair<string, int>

class Dictionary
{
    /* Simple class for storing data in dictionary...
    Hash Function : index
    Key : Words
    value : word count
     */
private:
    list<word> words[20]; // Intialization of word

public:
    Dictionary() {}
    void insert_word(string wd);
    int return_count(string wd);
};

int main()
{
    return 0;
}

void Dictionary::insert_word(string wd)
{
    // Using Length of the word as Hash-Function
    int index = int(wd.length()) - 1;

    // Appending Inside Linked-List in Increasing Order
    auto it = words[index].begin();
    for (; it != words[index].end(); it++)
    {
        if ((*it).first == wd)
        {
            (*it).second += 1;
            return;
        }
        if ((*it).first > wd)
            break;
    }
    words[index].insert(it, make_pair(wd, 1));
}

int Dictionary::return_count(string wd)
{
    int index = int(wd.length()) - 1;
    auto it = words[index].begin();
    for (; it != words[index].end(); it++)
    {
        if ((*it).first == wd)
            return (*it).second;
        if ((*it).first > wd)
            break;
    }
    return 0;
}