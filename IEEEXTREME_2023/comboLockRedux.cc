#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c = 0;
    cin >> c;
    for (int epoch = 0; epoch < c; epoch++)
    {
        int n, t, h0, a, b, q = 0, cur_h = 0;
        set<int> h_list;

        cin >> n >> t >> h0 >> a >> b >> q;
        cur_h = h0;
        while (find(h_list.begin(), h_list.end(), cur_h) == h_list.end())
        {
            h_list.insert(cur_h);
            cur_h = (a * cur_h + b) % q;
            cout << cur_h << endl;
        }
    }
    return 0;
}
