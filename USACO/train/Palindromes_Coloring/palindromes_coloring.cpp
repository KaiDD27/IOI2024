#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> charCount(26);
        for (char c : s)
        {
            charCount[c - 'a']++;
        }
        int cntPairs = 0, cntOdd = 0;
        for (int c : charCount)
        {
            cntPairs += c / 2;
            cntOdd += c % 2;
        }
        int ans = (cntPairs / k) * 2;
        cntOdd += 2 * (cntPairs % k);
        if (cntOdd >= k)
            ans++;
        cout << ans << endl;
    }
}