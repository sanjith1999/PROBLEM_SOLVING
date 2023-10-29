#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string a_str;
    double a;

    cin >> n;
    for (int epoch = 0; epoch < n; epoch++)
    {
        cin >> a_str;
        a = stod(a_str);

        // s_num*a = 90*k => s_num - 90*k/a
        double s_num = 0.1232345;
        long long factor = 1;
        while ((double)((long long)s_num) != s_num)
            s_num = 90 * factor/a , factor++;
        s_num = (s_num > 0) ? s_num : -s_num;
        cout << (long long)s_num << endl;
    }
    return 0;
}