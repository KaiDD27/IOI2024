// 递推，预处理
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
// n最大为 1e6,对于每一个行，有两种状态，0代表两个单独的块，1 代表横条
vector<array<ll, 2>> dp(1e6 + 10);
vector<ll> towerModulo;
void init() {
  dp[1][0] = 1, dp[1][1] = 1; // 第一行两种状态各有一种选择
  for (ll i = 2; i <= 1e6; i++) {
    // 两个单独的块，有四种方式来兼容上一行两个单独的块
    //  有1 种方式来兼容上一行的横条
    // 由于用的是ll所以不用每次加都取模
    dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
    // 横条有一种方式来兼容上一行两个单独的块
    // 两种方式来兼容上一行的横条
    dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  init();
  int t;
  cin >> t;
  towerModulo.resize(t);
  for (ll i = 0, n = 0; i < t; i++) {
    cin >> n;
    towerModulo[i] = (dp[n][0] + dp[n][1]) % MOD;
  }
  for (auto ti : towerModulo)
    cout << ti << endl;
  return 0;
}