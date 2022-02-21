#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    float a = 0, b = 0, c = 0, d = 0, r = 0, angle = 0;
    float h = 0, ab = 0, ratio = 0,angleRef=0;

    cin >> a >> b;
    cin >> c >> d;
    cin >> r;
    cin >> angle;

    ab = pow(pow(a - c, 2) + pow(b - d, 2), 0.5);
    h = pow(pow(r, 2) - pow(ab / 2, 2), 0.5);
    angleRef=round(2*asin(ab/r)*10)/10;

    if (ab > 2 * r || ab == 0 || angleRef != round(angle*10)/10)
    {
        cout << "Can not find a ratio" << endl;
    }
    else
    { //triangle area
        ratio = (0.5 * angle * pow(r, 2) - 0.5 * ab * h) / (0.5 * (2 * 3.14 - angle) * pow(r, 2) + 0.5 * ab * h);
        cout << round(ratio * 100) / 100 << endl;
        
    }
    return 0;
}