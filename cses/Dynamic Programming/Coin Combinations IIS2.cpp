// 递推
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
vector<vector<int>> dp;
vector<int> coin;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> coin[i];
  dp.resize(n + 1, vector<int>(x + 1, 0));
  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      dp[i][j] = dp[i - 1][j];
      if (coin[i] <= j) {
        dp[i][j] += dp[i][j - coin[i]];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[n][x] << endl;
}