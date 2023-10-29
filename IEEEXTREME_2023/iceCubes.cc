#include <bits/stdc++.h>
using namespace std;

int find_max(pair<int, int> cur_pos, int bad_count, int &N, int &M, int &B, int &tol, vector<vector<int>> &ice_cubes, vector<vector<vector<int>>> &ice_map)
{
    pair<int, int> r_cell, d_cell;
    int r_value, d_value, cur_value;
    bool shop_state;

    cur_value = ice_cubes[cur_pos.first][cur_pos.second];
    shop_state = ice_cubes[cur_pos.first][cur_pos.second] >= B;
    bad_count = (shop_state) ? 0 : bad_count + 1;
    if (bad_count == tol)
        return -1;

    if (ice_map[cur_pos.first][cur_pos.second][bad_count] != -2)
        return ice_map[cur_pos.first][cur_pos.second][bad_count];

    // At office
    if (cur_pos.first == N - 1 && cur_pos.second == M - 1)
    {
        ice_map[cur_pos.first][cur_pos.second][bad_count] = cur_value;
        return cur_value;
    }

    // Go Right
    r_cell = make_pair(cur_pos.first, cur_pos.second + 1);
    if (r_cell.second < M)
        r_value = find_max(r_cell, bad_count, N, M, B, tol, ice_cubes, ice_map);
    else
        r_value = -1;

    // Go Down
    d_cell = make_pair(cur_pos.first + 1, cur_pos.second);
    if (d_cell.first < N)
        d_value = find_max(d_cell, bad_count, N, M, B, tol, ice_cubes, ice_map);
    else
        d_value = -1;

    if (r_value > 0 && d_value > 0)
        ice_map[cur_pos.first][cur_pos.second][bad_count] = cur_value + max(d_value, r_value);
    else if (r_value > 0)
        ice_map[cur_pos.first][cur_pos.second][bad_count] = cur_value + r_value;
    else if (d_value > 0)
        ice_map[cur_pos.first][cur_pos.second][bad_count] = cur_value + d_value;
    else
        ice_map[cur_pos.first][cur_pos.second][bad_count] = -1;
    return ice_map[cur_pos.first][cur_pos.second][bad_count];
}

int main()
{
    int T = 0;
    cin >> T;
    for (int epoch = 1; epoch < T + 1; epoch++)
    {
        int N = 0, M = 0, K = 0, B = 0, ice = 0;
        cin >> N >> M >> K >> B;

        vector<vector<int>> ice_cubes(N, vector<int>(M));
        vector<vector<vector<int>>> ice_map(N, vector<vector<int>>(M, vector<int>(K)));
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
            {
                cin >> ice;
                ice_cubes[r][c] = ice;
                for (int k = 0; k < K; k++)
                {
                    ice_map[r][c][k] = -2;
                }
            }

        int result = find_max(make_pair(0, 0), 0, N, M, B, K, ice_cubes, ice_map);
        if (result == -1)
            cout << "Case " << epoch << ": IMPOSSIBLE" << endl;
        else
            cout << "Case " << epoch << ": " << result << endl;
    }

    return 0;
}