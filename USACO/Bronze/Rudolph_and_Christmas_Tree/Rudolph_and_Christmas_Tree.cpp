#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int T;
int main()
{
    cin >> T;
    int N;
    double D;
    double H;
    vector<int> baseHeights;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> D >> H;
        baseHeights = vector<int>(N, 0);
        for (int n = 0; n < N; n++)
        {
            int baseHeight = 0;
            cin >> baseHeight;
            baseHeights[n] = baseHeight;
        }

        sort(baseHeights.begin(), baseHeights.end());
        double area = 0;
        for (int i = 0; i < baseHeights.size(); i++)
        {
            if (i == baseHeights.size() - 1 || baseHeights[i + 1] - baseHeights[i] >= H)
            {
                area = area + D * H / 2;
            }
            else
            {
                double upD = (baseHeights[i] + H - baseHeights[i + 1]) * D / H;
                area = area + (D + upD) * (baseHeights[i + 1] - baseHeights[i]) / 2;
            }
        }
        cout << setprecision(10) << area << endl;
    }

    return 0;
}