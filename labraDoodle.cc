#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, width;
    string word;
    vector<string> dict;
    vector<int> prefix_ind[50];
    vector<int> suffix_ind[50];
    vector<string> prefix[50];
    vector<string> suffix[50];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        width = word.size();
        dict.push_back(word);

        for (int j = 3; j < width; j++)
        {
            (prefix[j-3]).push_back(word.substr(0, j));
            (prefix_ind[j - 3]).push_back(i);
            // suffix[width + 3 - j].push_back(word.substr(j - 3, width + 3 - j));
            // suffix_ind[width - j - 3].push_back(i);
        }
    }
    for (int epoch = 0; epoch < m; epoch++)
    {
        cin >> word;

        // ambiguous/ none/ words(could be same)
    }
    return 0;
}