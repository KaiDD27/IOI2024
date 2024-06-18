#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int N;
long long minX = 400001, minY = 400001, maxX = 0, maxY = 0;
long long computingMiniArea(vector<int> &threeCow, map<int, int> x_Nums, map<int, int> y_Nums, vector<pair<int, int>> cowsPosition)
{
    minX = x_Nums.begin()->first;
    maxX = x_Nums.rbegin()->first;
    minY = y_Nums.begin()->first;
    maxY = y_Nums.rbegin()->first;

    for (int i = 0; i < 3; i++)
    {
        switch (threeCow[i])
        {
        case 0:
            if (--y_Nums[maxY] == 0)
                y_Nums.erase(maxY);
            for (int j = 0; j < cowsPosition.size(); j++)
            {
                if (cowsPosition[j].second == maxY)
                {
                    if (cowsPosition[j].first != -1)
                    {
                        if (--x_Nums[cowsPosition[j].first] == 0)
                        {
                            x_Nums.erase(cowsPosition[j].first);
                        }
                        cowsPosition[j].first = -1;
                        break;
                    }
                }
            }
            break;
        case 1:
            if (--y_Nums[minY] == 0)
                y_Nums.erase(minY);
            for (int j = 0; j < cowsPosition.size(); j++)
            {
                if (cowsPosition[j].second == minY)
                {
                    if (cowsPosition[j].first != -1)
                    {
                        if (--x_Nums[cowsPosition[j].first] == 0)
                        {
                            x_Nums.erase(cowsPosition[j].first);
                        }
                        cowsPosition[j].first = -1;
                        break;
                    }
                }
            }
            break;
        case 2:
            if (--x_Nums[minX] == 0)
                x_Nums.erase(minX);
            for (int j = 0; j < cowsPosition.size(); j++)
            {
                if (cowsPosition[j].first == minX)
                {
                    if (cowsPosition[j].second != -1)
                    {
                        if (--y_Nums[cowsPosition[j].second] == 0)
                        {
                            y_Nums.erase(cowsPosition[j].second);
                        }
                        cowsPosition[j].second = -1;
                        break;
                    }
                }
            }
            break;
        case 3:
            if (--x_Nums[maxX] == 0)
                x_Nums.erase(maxX);
            for (int j = 0; j < cowsPosition.size(); j++)
            {
                if (cowsPosition[j].first == maxX)
                {
                    if (cowsPosition[j].second != -1)
                    {
                        if (--y_Nums[cowsPosition[j].second] == 0)
                        {
                            y_Nums.erase(cowsPosition[j].second);
                        }
                        cowsPosition[j].second = -1;
                        break;
                    }
                }
            }
            break;
        }
    }
    minX = x_Nums.begin()->first;
    maxX = x_Nums.rbegin()->first;
    minY = y_Nums.begin()->first;
    maxY = y_Nums.rbegin()->first;
    return (maxX - minX) * (maxY - minY);
}

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
        // minX = min(minX, XY.first);
        // minY = min(minY, XY.second);
        // maxX = max(maxX, XY.first);
        // maxY = max(maxY, XY.second);
    }

    long long miniArea = __LONG_LONG_MAX__;
    // Up,Down,Left,Right
    vector<int> threeCows;
    for (int firstCow = 0; firstCow < 4; firstCow++)
    {
        for (int secondCow = 0; secondCow < 4; secondCow++)
        {
            for (int thirdCow = 0; thirdCow < 4; thirdCow++)
            {
                threeCows = vector<int>{firstCow, secondCow, thirdCow};
                miniArea = min(miniArea, computingMiniArea(threeCows, x_Nums, y_Nums, cowsPosition));
            }
        }
    }
    fout << miniArea << endl;
}