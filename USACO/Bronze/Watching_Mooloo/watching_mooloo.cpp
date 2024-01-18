#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<long long> days(N);
    for (int i = 0; i < N; i++)
    {
        cin >> days[i];
    }

    sort(days.begin(), days.end());

    long long ans = K + 1;

    for (int i = 1; i < N; i++)
    {
        if (days[i] - days[i - 1] > K)
        {
            ans += K + 1;
        }
        else
        {
            ans += days[i] - days[i - 1];
        }
    }

    cout << ans << endl;

    return 0;
}