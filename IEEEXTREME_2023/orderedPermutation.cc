#include <bits/stdc++.h>
using namespace std;

bool validateRestriction(vector<int> &num, vector<char> &restrictions)
{
    for (int i = 0; i < num.size() - 1; i++)
    {
        bool failed = (restrictions[i] == '<' && num[i] > num[i + 1]) || (restrictions[i] == '>' && num[i] < num[i + 1]);
        if (failed)
            return false;
    }
    return true;
}
int main()
{
    int N;
    string res_type;
    vector<char> restrictions;
    vector<int> number;
    long possiblities=0;

    cin >> N;
    for (int i = 1; i < N + 1; i++)
        number.push_back(i);

    cin >> res_type;
    for (auto r : res_type)
        restrictions.push_back(r);
   
    // vector should be sorted at the beginning.

    do {
        if(validateRestriction(number,restrictions))
        possiblities++;

    } while (std::next_permutation(number.begin(),number.end()));
    cout<<possiblities<<endl;
    return 0;
}