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

        for (int j = 3; j < width + 1; j++)
        {
            (prefix[j - 3]).push_back(word.substr(0, j));
            (prefix_ind[j - 3]).push_back(i);
            suffix[width - j].push_back(word.substr(j - 3, width + 3 - j));
            suffix_ind[width - j].push_back(i);
        }
    }

    string pre_can, suf_can, pre_word, suf_word;
    int pre_size, suf_size;
    for (int epoch = 0; epoch < m; epoch++)
    {
        int count = 0;
        cin >> word;
        // ambiguous/ none/ words(could be same)
        for (int part = 3; part < word.size()+1 - 3; part++)
        { // Need to check at last the letter dropping thing
            // Without drop
            pre_can = word.substr(0, part), suf_can = word.substr(part, word.size() - part);

            pre_size = pre_can.size(),suf_size= suf_can.size();
            auto pre_pos = find(prefix[pre_size-3].begin(),prefix[pre_size-3].end(),pre_can);
            auto suf_pos = find(suffix[suf_size-3].begin(),suffix[suf_size-3].end(),suf_can);
            if (pre_pos!=prefix[pre_size-3].end() && suf_pos != suffix[suf_size-3].end())

            if (count > 1)
                break;
        }
        if (count == 0)
            cout << "none" << endl;
        else if (count == 1)
            cout << pre_word << " " << suf_word << endl;
        else
            cout << "ambiguous" << endl;
    }
    return 0;
}