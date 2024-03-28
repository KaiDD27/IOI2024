#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<ll>> dp;
vector<ll> x;
vector<ll> preSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    preSum[i] = preSum[i - 1] + x[i];
  }
  dp.resize(n + 1, vector<ll>(n + 1));
  for (int i = n; i >= 1; i--) { // i 表示序列的开头
    // j 表示序列的结尾
    for (int j = i; j <= n; j++) {
      if (i == j)
        dp[i][j] = x[i];
      else if (i + 1 == j)
        dp[i][j] = max(x[i], x[j]);
      else {
        // 先手有两个选择，后手在先手做出选择的基础上也有两个选择，而且后手也会做最好的选择，也就等于后手会造成先手上一轮是相对不好的选择
        dp[i][j] = max(x[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
                       x[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}