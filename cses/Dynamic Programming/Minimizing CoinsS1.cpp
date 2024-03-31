// 记忆化搜索
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> coin;
vector<ll> dp;
ll dfs(int x) {
  ll minNum = 1e6 + 1;
  if (x == 0)
    return dp[x] = 0;
  if (dp[x] != 1e6 + 2)
    return dp[x];
  for (int i = 0; i < coin.size(); i++) {
    if (x >= coin[i])
      minNum = min(minNum, dfs(x - coin[i]) + 1);
  }
  return dp[x] = minNum;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  dp.resize(x + 1, 1e6 + 2);

  for (auto &ci : coin)
    cin >> ci;
  dfs(x);
  if (dp[x] == 1e6 + 1)
    cout << -1 << endl;
  else
    cout << dp[x] << endl;
}