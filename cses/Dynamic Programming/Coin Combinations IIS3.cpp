// 空间优化
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
  dp.resize(2, vector<int>(x + 1, 0));
  int now = 0, old = 1;
  dp[now][0] = 1;
  dp[old][0] = 1;
  for (int i = 1; i <= n; i++) {
    swap(now, old);
    for (int j = 1; j <= x; j++) {
      dp[now][j] = dp[old][j];
      if (coin[i] <= j) {
        dp[now][j] += dp[now][j - coin[i]];
        dp[now][j] %= MOD;
      }
    }
  }
  cout << dp[now][x] << endl;
}