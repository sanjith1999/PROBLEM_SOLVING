#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T = 0, j = 0, l = 0;
    string DNA[101], cDNA[101];
    string dna, cDna;
    bool oneE = false, happen = false;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> DNA[i] >> cDNA[i];
    }

    for (int i = 0; i < T; i++)
    {
        happen = false;
        dna = DNA[i], cDna = cDNA[i];
        for (j = 0; j < dna.length() - cDna.length() + 1; j++)
        {
            if (dna[j] != cDna[0])
            {
                if (dna[j + 1] != cDna[1])
                {
                    continue;
                }
            }

            for (l = 0; l < cDna.length(); l++)
            {
                if (dna[j + l] != cDna[l])
                {
                    if (oneE)
                    {
                        break;
                    }
                    else
                    {
                        oneE = true;
                    }
                }
            }
            oneE=false;
            if (l == cDna.length())
            {
                happen = true;
                cout << j << " ";
            }
        }
        if(!happen){cout<<"No Match!";}
        cout<<endl;
    }

    return 0;
}