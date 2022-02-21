#include <bits/stdc++.h>

using namespace std;
int phiFunction(int);
int main()
{
    int answer = 1, count = 1000;
    float fracRef = 0;
    for (int number = 2; number < count + 1; number++)
    {
        if (fracRef < float(number) / phiFunction(number))
        {
            fracRef = float(number) / phiFunction(number);
            answer = number;
        }
    }
    cout<<answer<<endl;

    return 0;
}

int phiFunction(int n)
{
    int result = 0, i = 2;

    for (int m = 1; m < n; m++)
    {
        for (i = 2; i < m + 1; i++)
        {
            if (!(n % i || m % i))
            {
                break;
            }
        }
        if (i == m + 1 || m == 1)
        {
            result++;
        }
    }
    return result;
}