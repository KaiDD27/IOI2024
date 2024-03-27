// https : // www.acwing.com/problem/content/273/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 31;

int n;
ll dp[N][N][N][N][N];
vector<int> s(5, 0);
int main() {
  while (cin >> n, n) {
    fill(s.begin(), s.end(), 0);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0] = 1;

    for (int a = 0; a <= s[0]; a++)
      for (int b = 0; b <= min(a, s[1]); b++)
        for (int c = 0; c <= min(b, s[2]); c++)
          for (int d = 0; d <= min(c, s[3]); d++)
            for (int e = 0; e <= min(d, s[4]); e++) {
              ll &x = dp[a][b][c][d][e];
              if (a && a - 1 >= b)
                x += dp[a - 1][b][c][d][e];
              if (b && b - 1 >= c)
                x += dp[a][b - 1][c][d][e];
              if (c && c - 1 >= d)
                x += dp[a][b][c - 1][d][e];
              if (d && d - 1 >= e)
                x += dp[a][b][c][d - 1][e];
              if (e)
                x += dp[a][b][c][d][e - 1];
            }
    cout << dp[s[0]][s[1]][s[2]][s[3]][s[4]] << endl;
  }

  return 0;
}