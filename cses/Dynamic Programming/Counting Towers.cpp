#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll modNum = 1e9 + 7;
vector<array<ll, 2>> dp(1e6 + 1); // 0代表单独的块，1 代表横条
vector<ll> towerModulo;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int t;
  cin >> t;
  towerModulo.resize(t);
  dp[1][0] = 1, dp[1][1] = 1;
  for (ll i = 0, n = 0, maxHeight = 1; i < t; i++) {
    cin >> n;
    if (n <= maxHeight) {
      towerModulo[i] = (dp[n][0] + dp[n][1]) % modNum;
      continue;
    }
    for (ll j = maxHeight + 1; j <= n; j++) {
      dp[j][0] = (4 * dp[j - 1][0] + dp[j - 1][1]) % modNum;
      dp[j][1] = (dp[j - 1][0] + 2 * dp[j - 1][1]) % modNum;
    }
    towerModulo[i] = (dp[n][0] + dp[n][1]) % modNum;
    maxHeight = n;
  }
  for (auto ti : towerModulo)
    cout << ti << endl;
  return 0;
}