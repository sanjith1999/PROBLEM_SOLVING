#include <bits/stdc++.h>
using namespace std;

int main()
{
    long N, n, cur_min;
    vector<long> min_list;
    vector<long> prefix;

    cin >> N;

    for (long i = 0; i < N; i++)
    {
        cin >> n;
        if (!i)
        {
            prefix.push_back(n);
            cur_min = n;
        }
        else if (n >= *(prefix.end()-1))
        {
            prefix.push_back(n);
            min_list.push_back(cur_min);
            cur_min = n;
        }
        else if (n < cur_min)
            cur_min = n;
    }
    min_list.push_back(cur_min);
    int count = 0;
    // Evaluating how many candidates viable
    for (int i = 0;i<min_list.size();i++){
        if (i==min_list.size()-1 || prefix[i] <= *min_element(next(min_list.begin(),i+1),min_list.end()))
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}