#include <bits/stdc++.h>
using namespace std;

int findSquSum(int num)
{
    int s_sum = 0;
    for (char digit : to_string(num))
        if (isdigit(digit))
            s_sum += pow((digit - '0'), 2);
    return s_sum;
}

short int checkHappy(int n, vector<short int> &happy_)
{
    if (happy_[n] != -1)
        return happy_[n];
    return checkHappy(findSquSum(n), happy_);
}

long happyBelow(vector<int> &num_list){
    long possiblities = 0;
    short int width = (short int)num_list.size();
    for (int i = 0; i<width ;i++)
        
    return possiblities;
}

int main()
{
    int max_pos = 245;
    vector<short int> happy_list(max_pos, -1);
    for (int i = 0; i < 10; i++)
        happy_list[i] = 0;
    happy_list[1] = 1;

    for (int i = 10; i < max_pos; i++)
        happy_list[i] = checkHappy(i, happy_list);

    string a, b;
    int happy_count = 0;
    vector<short int> a_list, b_list;

    cin >> a >> b;

    for (char digit : a)
        if (isdigit(digit))
            a_list.push_back(digit - '0');
    for (char digit : b)
        if (isdigit(digit))
            b_list.push_back(digit - '0');
    




    cout << happy_count;
    return 0;
}
