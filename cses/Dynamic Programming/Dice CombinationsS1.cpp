// 记忆化搜索
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<ll> dp;
ll dfs(ll sumD) {
  if (sumD == 0)
    return 1;
  if (dp[sumD] != 0)
    return dp[sumD];
  for (int dice = 1; dice <= 6; dice++) {
    if (sumD >= dice) {
      dp[sumD] += dfs(sumD - dice);
      dp[sumD] %= MOD;
    }
  }
  return dp[sumD];
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  dp.resize(n + 1);
  cout << dfs(n) << endl;
  return 0;
}