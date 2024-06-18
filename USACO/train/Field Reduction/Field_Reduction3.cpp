#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int N;
long long minX = 400001, minY = 400001, maxX = 0, maxY = 0;
long long miniArea = __LONG_LONG_MAX__;

int main()
{
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    fin >> N;
    vector<pair<int, int>> cowsPosition;
    map<int, int> x_Nums, y_Nums;

    for (int n = 0; n < N; n++)
    {
        int x, y;

        fin >> x >> y;
        if (x_Nums.count(x) > 0)
            x_Nums[x]++;
        else
            x_Nums[x] = 1;
        if (y_Nums.count(y) > 0)
            y_Nums[y]++;
        else
            y_Nums[y] = 1;
        cowsPosition.push_back(pair<int, int>(x, y));
    }

    // Up,Down,Left,Right

    vector<int> upBoard, downBoard, leftBoard, rightBoard;
    int pointersCount = 0;
    for (auto it = x_Nums.begin(); it != x_Nums.end(); it++)
    {
        leftBoard.push_back(it->first);
        pointersCount += it->second;
        if (pointersCount >= 4)
        {
            break;
        }
    }

    pointersCount = 0;
    for (auto it = x_Nums.rbegin(); it != x_Nums.rend(); it++)
    {
        rightBoard.push_back(it->first);
        pointersCount += it->second;
        if (pointersCount >= 4)
        {
            break;
        }
    }

    pointersCount = 0;
    for (auto it = y_Nums.rbegin(); it != y_Nums.rend(); it++)
    {
        upBoard.push_back(it->first);
        pointersCount += it->second;
        if (pointersCount >= 4)
        {
            break;
        }
    }

    pointersCount = 0;
    for (auto it = y_Nums.begin(); it != y_Nums.end(); it++)
    {
        downBoard.push_back(it->first);
        pointersCount += it->second;
        if (pointersCount >= 4)
        {
            break;
        }
    }

    for (int i = 0; i < upBoard.size(); i++)
        for (int j = 0; j < downBoard.size(); j++)
            for (int m = 0; m < leftBoard.size(); m++)
                for (int n = 0; n < rightBoard.size(); n++)
                {
                    int count = 0;
                    maxY = upBoard[i];
                    minY = downBoard[j];
                    minX = leftBoard[m];
                    maxX = rightBoard[n];
                    for (int c = 0; c < cowsPosition.size(); c++)
                    {
                        if (cowsPosition[c].first < minX || cowsPosition[c].first > maxX || cowsPosition[c].second < minY || cowsPosition[c].second > maxY)
                            if (++count > 3)
                                break;
                    }

                    if (count <= 3)
                        miniArea = min(miniArea, (maxX - minX) * (maxY - minY));
                }

    fout << miniArea << endl;
}