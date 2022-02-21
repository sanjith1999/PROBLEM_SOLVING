#include <iostream>
#include <vector>

using namespace std;

int minSideJumps(vector<int> &);

int main()
{
    //test cases
    vector<int> obstacles1 = {0, 1, 1, 3, 3, 0}; //output 0
    vector<int> obstacles2 = {0, 1, 2, 3, 0};    //output 2
    vector<int> obstacles3 = {0, 2, 1, 0, 3, 0}; //output 2
    vector<int> obstacles4={0,2,2,1,0,3,0,3,0,1,3,1,1,0,1,3,1,1,1,0,2,0,0,3,3,0,3,2,2,0,0,3,3,3,0,0,2,0,0,3,3,0,3,3,0,0,3,1,0,1,0,2,3,1,1,0,3,3,0,3,1,3,0,2,2,0,1,3,0,1,0,3,0,1,3,1,2,2,0,0,3,0,1,3,2,3,2,1,0,3,2,2,0,3,3,0,3,0,0,1,0}; //output 14

    cout << minSideJumps(obstacles4) << endl;

    return 0;
}

int minSideJumps(vector<int> &obstacles)
{
    short int currentLane = 2, aLane1 = 3, aLane2 = 1, ref = 0;
    int L1 = 0, L2 = 0, sideJumps = 0;
    bool aL1 = true, aL2 = true;
    for (auto it = obstacles.begin(); it != obstacles.end()-1; it++)
    {
        if (currentLane != *(it+1))
        {
            continue;
        }

        for (auto count = it; count != obstacles.end() && (aL1 || aL2); count++)
        {
            if (aL1 && *count == aLane1)
            {
                aL1 = false;
            }
            if (aL2 && *count == aLane2)
            {
                aL2 = false;
            }
            if (aL1)
            {
                L1++;
            }
            if (aL2)
            {
                L2++;
            }
        }
        if (L2 > L1)
        {
            ref = aLane2, aLane2 = currentLane, currentLane = ref;
        }
        else
        {
            ref = aLane1, aLane1 = currentLane, currentLane = ref;
        }
        sideJumps++;
        L1 = 0, L2 = 0,aL1=true,aL2=true;
    }
    return sideJumps;
}

