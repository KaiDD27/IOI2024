#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> beautyMap;

int main(void)
{
    cin >> N;
    beautyMap = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> beautyMap[i][j];
        }
    }

    int xHightestBeauty = 0;
    int yHightestBeauty = 0;
    // 按照第一行来选择
    for (int x = 0; x < N; x++)
    {
        int oddBeauty = 0;
        int evenBeauty = 0;
        for (int y = 0; y < N; y++)
        {
            if (y % 2 == 0)
            {
                evenBeauty += beautyMap[y][x];
            }
            else
                oddBeauty += beautyMap[y][x];
        }
        xHightestBeauty += max(evenBeauty, oddBeauty);
    }

    for (int y = 0; y < N; y++)
    {
        int oddBeauty = 0;
        int evenBeauty = 0;
        for (int x = 0; x < N; x++)
        {
            if (x % 2 == 0)
            {
                evenBeauty += beautyMap[y][x];
            }
            else
                oddBeauty += beautyMap[y][x];
        }
        yHightestBeauty += max(evenBeauty, oddBeauty);
    }

    cout << max(xHightestBeauty, yHightestBeauty) << endl;
    return 0;
}