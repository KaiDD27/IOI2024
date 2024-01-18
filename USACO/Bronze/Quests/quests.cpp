#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T, N, K;
    cin >> T;
    vector<int> firstCompletionEXP, subsequentCompletionEXP;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        firstCompletionEXP = vector<int>(N);
        subsequentCompletionEXP = vector<int>(N);

        for (int j = 0; j < N; j++)
        {
            cin >> firstCompletionEXP[j];
        }
        for (int j = 0; j < N; j++)
        {
            cin >> subsequentCompletionEXP[j];
        }
        int totalFirstExp = 0, maxTotalExp = 0, maxSubExp = 0;
        for (int j = 0; j < min(K, N); j++)
        {
            totalFirstExp += firstCompletionEXP[j];
            maxSubExp = max(maxSubExp, subsequentCompletionEXP[j]);
            maxTotalExp = max(maxTotalExp, totalFirstExp + (K - j - 1) * maxSubExp);
        }

        cout << maxTotalExp << endl;
    }
    return 0;
}