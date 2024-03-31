// 暴力搜索
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> coin;
ll dfs(int x) {
  ll minNum = 1e6 + 1;
  if (x == 0)
    return 0;
  for (int i = 0; i < coin.size(); i++) {
    if (x >= coin[i])
      minNum = min(minNum, dfs(x - coin[i]) + 1);
  }
  return minNum;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  ll ans = dfs(x);
  if (ans == 1e6 + 1)
    cout << -1 << endl;
  else
    cout << ans << endl;
}