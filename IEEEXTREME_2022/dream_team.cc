#include <bits/stdc++.h>
using namespace std;

struct team_mem
{
    int p, g, s, f, c;
    long long salary;
};

int main()
{
    int P, G, S, F, C;
    long long B, w, salary = 0;
    string player;
    vector<pair<long long, pair<int, int>>> pg_combination; // REDUCING THE TIME COMPLEXITY BY CONSIDERING P AND G ALONE
    vector<pair<int, string>> point_guard, shoot_guard, small_forward, power_forward, center;
    team_mem dream_team, temp_team;
    dream_team.salary = 0;

    cin >> B;
    cin >> P;
    for (int c = 0; c < P; c++)
    {
        cin >> player >> w;
        point_guard.push_back({w, player});
    }
    cin >> G;
    for (int c = 0; c < G; c++)
    {
        cin >> player >> w;
        shoot_guard.push_back({w, player});
    }
    cin >> S;
    for (int c = 0; c < S; c++)
    {
        cin >> player >> w;
        small_forward.push_back({w, player});
    }
    cin >> F;
    for (int c = 0; c < F; c++)
    {
        cin >> player >> w;
        power_forward.push_back({w, player});
    }
    cin >> C;
    for (int c = 0; c < C; c++)
    {
        cin >> player >> w;
        center.push_back({w, player});
    }
    for (int p = 0; p < P; p++)
        for (int g = 0; g < G; g++)
        {
            salary = point_guard[p].first + shoot_guard[g].first;
            pg_combination.push_back({salary, {p, g}});
        }
    sort(pg_combination.begin(), pg_combination.end());

    // LAMBDA FUNCTION FOR COMPARING TWO TEAMS
    auto compare_teams = [&](team_mem team1, team_mem team2)
    {
        // TEAM 1 > TEAM 2 : RETURN TRUE
        // POINT GUARD
        if (point_guard[team1.p].second < point_guard[team2.p].second)
            return true;
        else if (point_guard[team1.p].second > point_guard[team2.p].second)
            return false;
        // SHOOT GUARD
        if (shoot_guard[team1.g].second < shoot_guard[team2.g].second)
            return true;
        else if (shoot_guard[team1.g].second > shoot_guard[team2.g].second)
            return false;
        // SMALL FORWARD
        if (small_forward[team1.s].second < small_forward[team2.s].second)
            return true;
        else if (small_forward[team1.s].second > small_forward[team2.s].second)
            return false;
        // POWER FORWARD
        if (power_forward[team1.f].second < power_forward[team2.f].second)
            return true;
        else if (power_forward[team1.f].second > power_forward[team2.f].second)
            return false;
        // CENTER
        if (center[team1.c].second < center[team2.c].second)
            return true;
        return false;
    };

    for (int i3 = 0; i3 < S; i3++)              // SMALL FORWARD
        for (int i4 = 0; i4 < F; i4++)          // POWER FORWARD
            for (int i5 = 0; i5 < C; i5++)      // CENTER
                for (int i = 0; i < P * G; i++) // P-G COMBINATIONS
                {
                    salary = pg_combination[i].first + small_forward[i3].first + power_forward[i4].first + center[i5].first;
                    if (salary > B)
                        break;
                    if (salary > dream_team.salary)
                        dream_team.p = pg_combination[i].second.first, dream_team.g = pg_combination[i].second.second, dream_team.s = i3, dream_team.f = i4, dream_team.c = i5, dream_team.salary = salary;
                    else if (salary == dream_team.salary)
                    {
                        temp_team.p = pg_combination[i].second.first, temp_team.g = pg_combination[i].second.second, temp_team.s = i3, temp_team.f = i4, temp_team.c = i5, temp_team.salary = salary;
                        if (compare_teams(dream_team, temp_team))
                            swap(temp_team, temp_team);
                    }
                }
    cout << point_guard[dream_team.p].second << endl;
    cout << shoot_guard[dream_team.g].second << endl;
    cout << small_forward[dream_team.s].second << endl;
    cout << power_forward[dream_team.f].second << endl;
    cout << center[dream_team.c].second << endl;
    return 0;
}
