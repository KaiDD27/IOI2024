// 递推
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> coin;
vector<int> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  dp.resize(x + 1);
  dp[0] = 0;
  for (int iSum = 1; iSum <= x; iSum++) {
    dp[iSum] = 1e6 + 1; // x 个面值为1 的硬币是上限。
    for (auto ci : coin) {
      if (iSum - ci >= 0)
        dp[iSum] = min(dp[iSum], dp[iSum - ci] + 1);
    }
  }
  if (dp[x] != 1e6 + 1)
    cout << dp[x] << endl;
  else
    cout << "-1" << endl;
  return 0;
}