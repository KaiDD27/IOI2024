#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int mn = 0, mx = INT32_MAX;
        for (int j = 0; j + 1 < N; j++)
        {
            int x = A[j], y = A[j + 1];
            int midLow = (x + y) / 2, midHigh = (x + y + 1) / 2; // 利用这个整除特性，如果xy 的和是偶数，则即使加 1 也不会改变值。
            if (x < y)
                mx = min(mx, midLow);
            if (x > y)
                mn = max(mn, midHigh);
        }
        if (mn <= mx)
            cout << mn << endl;
        else
            cout << -1 << endl;
    }
}