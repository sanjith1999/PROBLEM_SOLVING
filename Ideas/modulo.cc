#include <bits/stdc++.h>
using namespace std;

const long long MOD = pow(10, 9) + 7;

int modInverse(int a, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        long long q = a / m;
        long long t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    int q_inv = modInverse(7, MOD);
    int p = 6;
    cout << (p * q_inv) % MOD << endl;
    return 0;
}

