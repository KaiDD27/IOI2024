#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<long long> hunger(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> hunger[i];
    }

    long long bags_needed = 0;

    for (int i = 1; i < N; i++)
    {
        if (hunger[i] > hunger[i + 1])
        {
            if (i % 2 == 1)
            {
                cout << -1 << endl;
                return;
            }

            long long difference = hunger[i] - hunger[i + 1];
            bags_needed += difference * i;
        }
        else if (hunger[i] < hunger[i + 1])
        {
            if (i + 2 > N)
            {
                cout << -1 << endl;
                return;
            }
            long long difference = hunger[i + 1] - hunger[i];
            hunger[i + 1] -= difference;
            hunger[i + 2] -= difference;
            if (hunger[i + 2] < 0)
            {
                cout << -1 << endl;
                return;
            }
            bags_needed += difference * 2;
        }
    }
    cout << bags_needed << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solve();
    }
}