// 暴力搜索
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
vector<int> coin;
ll dfs(ll coinIndex, ll x) {
  if (x == 0)
    return 1;
  if (coinIndex == -1 && x != 0)
    return 0;
  ll numWays = 0;
  for (int i = 0; x >= i * coin[coinIndex]; i++) {
    numWays += dfs(coinIndex - 1, x - i * coin[coinIndex]);
    numWays %= MOD;
  }

  return numWays;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  cout << dfs(n - 1, x) << endl;
}