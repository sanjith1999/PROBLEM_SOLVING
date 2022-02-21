#include <iostream>
#include <vector>
using namespace std;

vector<int> climbingLeaderboard(vector<int>, vector<int>);

int main()
{
    vector<int> arr1 = {100, 90, 90, 80, 75, 60};
    vector<int> arr2 = {50, 65, 77, 90, 102};

    vector<int> res = climbingLeaderboard(arr1, arr2);
    for (auto t = res.begin(); t != res.end(); t++)
    {
        cout << *t << endl;
    }

    return 0;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> rank, rplayer, rresult, result;
    int count = 1;
    rank.push_back(ranked[0]);
    for (auto t = ranked.begin() + 1; t != ranked.end(); ++t)
    {
        if (rank[count - 1] != *t)
        {
            rank.push_back(*t);
            count += 1;
        }
    }

    for (auto t = player.end() - 1; t != player.begin() - 1; --t)
    {
        rplayer.push_back(*t);
    }

    int reference = 0;
    for (auto t = rplayer.begin(); t != rplayer.end(); ++t)
    {
        for (; reference < rank.size(); reference++)
        {

            if (rank[reference] <= *t)
            {
                rresult.push_back(reference + 1);
                break;
            }
        }
        if (reference == rank.size())
        {
            rresult.push_back(reference + 1);
        }
    }

    for (auto t = rresult.end() - 1; t != rresult.begin() - 1; --t)
    {
        result.push_back(*t);
    }
    return result;
}
