// 记忆化搜索，内存最大到381MB了，空间没爆，单递归太多层，时间爆了
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
vector<int> coin;
vector<vector<int>> dp;
ll dfs(ll coinIndex, ll x) {
  if (coinIndex == -1 && x != 0)
    return 0;
  if (coinIndex == -1 && x == 0)
    return 1;

  if (x == 0)
    return dp[coinIndex][x] = 1;

  if (dp[coinIndex][x] != -1)
    return dp[coinIndex][x];
  ll numWays = 0;
  for (int i = 0; x >= i * coin[coinIndex]; i++) {
    numWays += dfs(coinIndex - 1, x - i * coin[coinIndex]);
    numWays %= MOD;
  }
  return dp[coinIndex][x] = numWays;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  dp.resize(n, vector<int>(x + 1, -1));
  cout << dfs(n - 1, x) << endl;
}