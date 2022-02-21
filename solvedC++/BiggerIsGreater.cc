#include <iostream>
#include <string>
using namespace std;

string biggerIsGreater(string);

int main()
{
    cout << biggerIsGreater("aaabbbbaaa") << endl;

    return 0;
}

string biggerIsGreater(string w)
{
    char ref = 'a';
    for (int count = w.size() - 1; count >= 0; count--)
    {
        if (w[w.size() - 1] > w[count])
        {
            //finding the next element to the current element and replace it with that one...
            for (int count1 = count; count1 < w.size() - 1; count1++)
            {
                if (w[count1] < w[count1 + 1])
                {
                    w.insert(w.begin() + count, w[count1 + 1]);
                    w.erase(w.begin() + count1 + 2);
                    return w;
                }
                ref = w[count1];
                w[count1] = (w[count1 + 1] < w[count1]) ? w[count1 + 1] : w[count1];
                w[count1 + 1] = (w[count1 + 1] < ref) ? ref : w[count1 + 1];
            }
        }
        //sorting the parts beyond pointer in acending order....
        w.push_back(w[count]);
        w.erase(w.begin() + count);
    }
    return "no answer";
}
