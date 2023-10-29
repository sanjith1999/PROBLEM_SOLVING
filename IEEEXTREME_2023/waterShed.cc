#include <bits/stdc++.h>
using namespace std;

bool relaxWater(vector<vector<double>> &water_level, vector<vector<int>> &elevation, int rows, int cols)
{
    pair<int, int> u_cell, r_cell, d_cell, l_cell;
    map<short int, bool> can_flow;
    double water = 0;
    int e = 0;
    short int partition = 0;
    bool relaxed = false;

    auto validateCell = [rows, cols](pair<int, int> cell)
    { if(cell.first>-1 && cell.second>-1 && cell.first<rows&& cell.second<cols)return true;return false; };

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
        {
            e = elevation[r][c];

            // ADJACENT CELL ASSIGNMENT
            u_cell = make_pair(r - 1, c), r_cell = make_pair(r, c + 1), d_cell = make_pair(r + 1, c), l_cell = make_pair(r, c - 1);
            if (validateCell(u_cell) && elevation[u_cell.first][u_cell.second] < e)
                can_flow[0] = true, partition = 1;
            else
                can_flow[0] = false, partition = 0;
            if (validateCell(r_cell) && elevation[r_cell.first][r_cell.second] < e)
                can_flow[1] = true, partition++;
            else
                can_flow[1] = false;
            if (validateCell(d_cell) && elevation[d_cell.first][d_cell.second] < e)
                can_flow[2] = true, partition++;
            else
                can_flow[2] = false;
            if (validateCell(l_cell) && elevation[l_cell.first][l_cell.second] < e)
                can_flow[3] = true, partition++;
            else
                can_flow[3] = false;

            // WATER TREATMENT
            if (partition > 0)
                water = water_level[r][c] / partition, water_level[r][c] = 0;
            if (can_flow[0])
                water_level[u_cell.first][u_cell.second] += water;
            if (can_flow[1])
                water_level[r_cell.first][r_cell.second] += water;
            if (can_flow[2])
                water_level[d_cell.first][d_cell.second] += water;
            if (can_flow[3])
                water_level[l_cell.first][l_cell.second] += water;
            if (water > 0 && partition > 0)
                relaxed = true;
        }
    return relaxed;
}

int main()
{
    int n, m, ele;
    cin >> n >> m;

    vector<vector<double>> water_level(n, vector<double>(m));
    vector<vector<int>> elevation(n, vector<int>(m));

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
        {
            cin >> ele;
            elevation[r][c] = ele;
            water_level[r][c] = 1;
        }

    while (relaxWater(water_level, elevation, n, m))
        continue;

    vector<double> max_water;
    for (int r=0;r<n;r++)max_water.push_back(*max_element(water_level[r].begin(),water_level[r].end()));
    cout<<*max_element(max_water.begin(),max_water.end())<<endl;
    return 0;
}