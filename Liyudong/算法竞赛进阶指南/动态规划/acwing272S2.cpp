// https://www.acwing.com/problem/content/description/274/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a, b;
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  a.resize(n + 1);
  b.resize(n + 1);
  dp.resize(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  for (int i = 1; i <= n; i++) {
    int maxV = 1;
    for (int j = 1; j <= n; j++) {

      if (b[j] == a[i])
        dp[i][j] = max(dp[i][j], maxV);
      else
        dp[i][j] = dp[i - 1][j];

      // 为下一个j做准备
      if (b[j] < a[i]) {
        maxV = max(maxV, dp[i - 1][j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}