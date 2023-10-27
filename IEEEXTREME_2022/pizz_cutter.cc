#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    set<int> angles;
    cin >> T;
    for (int c = 0; c < T; c++)
    {
        int N = 0, angle = 0;
        angles.clear();
        cin >> N;
        for (int a = 0; a < N; a++)
        {
            cin >> angle;
            angle = ((angle % 360) + 360) % 180;
            angles.insert(angle);
        }
        cout << max((int)angles.size() * 2, 1) << endl;
    }
    return 0;
}