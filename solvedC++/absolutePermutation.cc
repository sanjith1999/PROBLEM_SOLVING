#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> absolutePermutation(int, int);

int main()
{

    //auto start = high_resolution_clock::now();
    absolutePermutation(10,3);
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);

    //cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

/* Function for absolute permutation related with k */
vector<int> absolutePermutation(int n, int k)
{
    vector<int> result(n, 0);
    int refCount = 0;
    if (n % 2 && k)
    {
        return {-1};
    }

    for (int point = 0; point < n; point++)
    {
        if (!result[point] && point+k < n)
        {
            result[point] = point + k + 1;
            result[point + k] = point + 1;
            refCount++;
        }
    }
    if ((refCount >= n / 2 && !(n % 2)) || refCount > n / 2)
    {
        return result;
    }
    return {-1};
}