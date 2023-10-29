#include <bits/stdc++.h>

using namespace std;

bool stringChecker(string &pas1, string &pas2, vector<vector<string>> &sequences)
{
    string suffix1, prefix1, suffix2, prefix2, candidate;
    // Let us check whether a word in pas 1
    for (auto sequence : sequences)
    {
        for (auto word : sequence)
        {
            size_t pos = pas1.find(word);
            while (pos != string::npos)
            {
                // Finding a suitable candidate for
                prefix1 = pas1.substr(0, pos);
                suffix1 = pas1.substr(pos + word.size(), pas1.size()-word.size()-prefix1.size());

                if (pas2.size() > prefix1.size() + suffix1.size())
                {
                    prefix2 = pas2.substr(0, prefix1.size());
                    suffix2 = pas2.substr(pas2.size() - suffix1.size(), suffix1.size());
                    if (prefix1 == prefix2 && suffix1 == suffix2)
                    {
                        candidate = pas2.substr(pos, pas2.size() - suffix2.size()-prefix2.size());

                        if (find(sequence.begin(), sequence.end(), candidate) != sequence.end())
                            return true;
                    }
                }
                pos = pas1.find(word, pos + 1);
            }
        }
    }
    return false;
}

int main()
{
    int n, m, p;
    string temp_str, pas1, pas2;
    vector<vector<string>> sequences;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<string> temp_seq;
        string temp_str;
        for (int j = 0; j < m; j++)
        {
            cin >> temp_str;
            temp_seq.push_back(temp_str);
        }
        sequences.push_back(temp_seq);
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> pas1 >> pas2;
        if (stringChecker(pas1, pas2, sequences))
            cout << "REJECT" << endl;
        else
            cout << "OK" << endl;
    }
    return 0;
}




