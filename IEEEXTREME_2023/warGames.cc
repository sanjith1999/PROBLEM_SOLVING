#include <bits/stdc++.h>
using namespace std;

map<char, short int> game_map = {
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13},
    {'A', 14}};

void playGame(queue<short int> &p1, queue<short int> &p2)
{
    int count = 0;
    while (!p1.empty() && !p2.empty() && count < 10000)
    {
        if (p2.front() > p1.front())
            p2.pop(), p2.push(p1.front()), p1.pop();
        else if (p1.front() > p2.front())
            p1.pop(), p1.push(p2.front()), p2.pop();
        else
            p1.push(p1.front()), p1.pop(), p2.push(p2.front()),p2.pop();
        count ++;
    }
    if (p1.empty())
        cout << "player 2" << endl;
    else if (p2.empty())
        cout << "player 1" << endl;
    else
        cout << "draw" << endl;
    return ;
}

int main()
{
    int n = 0;
    string line;
    char temp;

    cin >> n;
    getline(cin, line);

    for (int epoch = 0; epoch < n; epoch++)
    {
        queue<short int> p1, p2;
        getline(cin, line);
        for (auto c : line)

        {
            if (game_map[c] != 0)
                p1.push(game_map[c]);
        }
        getline(cin, line);
        for (auto c : line)
        {
            if (game_map[c] != 0)
                p2.push(game_map[c]);
        }

        playGame(p1, p2);
    }
    return 0;
}