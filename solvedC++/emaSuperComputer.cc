#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
int twoPluses(vector<string> &, int, int);
int main()
{
    int n = 10, m = 10;
    string s[23];
    vector<string> sanjith;
    vector<string> GRID = {"BBBBBGGBGG", "GGGGGGGGGG", "GGGGGGGGGG", "BBBBBGGBGG", "BBBBBGGBGG", "GGGGGGGGGG", "BBBBBGGBGG", "GGGGGGGGGG", "BBBBBGGBGG", "GGGGGGGGGG"};
    sanjith.push_back("sanjith");
    cout << twoPluses(GRID, n, m) << endl;
    return 0;
}

int twoPluses(vector<string> &grid, int n, int m)
{
    vector<int> LENGTHS;
    vector<pair<int, int>> cellRef;
    int i = 0, count = 0, largestArea = 0;

    //going for lengths from maximum possible value....
    for (int length = (min(n, m) % 2) ? min(n, m) : min(n, m) - 1; length > 0; length -= 2)
    {
        //going through posible values for row with a certain length
        for (int row = length / 2; row < n - length / 2; row++)
        {
            //going through possible value fors column with a certain length
            for (int column = 0; column < m - length + 1; column++)
            {
                //checking whether overlap happen with existing pluses and put 1 when overlap happen
                vector<int> overlap(count, 0);

                for (i = 0; i < length; i++)
                {
                    if (grid[row][column + i] != 'G' || grid[row - length / 2 + i][column + length / 2] != 'G')
                    {
                        break;
                    }
                    for (int j = 0; j < count; j++)
                    {
                        //checking whether overlap happen at any instance
                        if ((row == cellRef[j].first && cellRef[j].second <= column + i && column + i < cellRef[j].second + LENGTHS[j]) || (column + i == cellRef[j].second + LENGTHS[j] / 2 && cellRef[j].first + LENGTHS[j] / 2 >= row && cellRef[j].first - LENGTHS[j] / 2 <= row) ||
                            (row - length / 2 + i == cellRef[j].first && cellRef[j].second <= column + length / 2 && column + length / 2 < cellRef[j].second + LENGTHS[j]) || (column + length / 2 == cellRef[j].second + LENGTHS[j] / 2 && cellRef[j].first + LENGTHS[j] / 2 >= row - length / 2 + i && cellRef[j].first - LENGTHS[j] / 2 <= row - length / 2 + i))
                        {
                            overlap[j] = 1;
                        }
                    }
                }
                if (i == length)
                {
                    for (int j = 0; j < count; j++)
                    {
                        if (overlap[j] == 0)
                        {
                            if (largestArea < (2 * length - 1) * (2 * LENGTHS[j] - 1))
                            {
                                largestArea = (2 * length - 1) * (2 * LENGTHS[j] - 1);
                            }
                        }
                    }

                    //appending possible length and cellRef(left most cell of a possible plus)
                    LENGTHS.push_back(length);
                    cellRef.push_back(make_pair(row, column));
                    count++;
                }
            }
        }
    }
    return largestArea;
}
