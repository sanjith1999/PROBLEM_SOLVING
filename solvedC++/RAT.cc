#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    float covid[50], threshold[50];
    float H, t;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> covid[i] >> threshold[i];
    }

    for (int i = 0; i < T; i++)
    {
        H = covid[i], t = threshold[i];
        for (int j = 0; j < 5; j++)
        {
            
            H = (0.4 * H) / (H * 0.4 + (1 - H) * 0.6);
            if (H < t)
            {
                cout << j + 1 << endl;
                break;
            }

        }
        if (H >= t)
        {
            cout << "NOT SUITABLE" << endl;
        }
    }
    return 0;
}
