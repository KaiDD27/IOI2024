// 递推,空间优化
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<ll> dp;
vector<vector<bool>> gridAvailable;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  gridAvailable.resize(n + 1, vector<bool>(n + 1));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      gridAvailable[i][j] = s[j - 1] == '.' ? true : false;
    }
  }
  dp.resize(n + 1, 0);
  if (gridAvailable[1][1] == true && gridAvailable[n][n] == true)
    dp[1] = 1;
  else {
    cout << 0 << endl;
    return 0;
  }
  for (int line = 1; line <= n; line++) {
    for (int column = 1; column <= n; column++) {
      if (gridAvailable[line][column] == false) {
        dp[column] = 0;
        continue;
      }
      // 特判第一行dp[1]为 1
      if (line == 1 && column == 1) {
        dp[column] = 1;
        continue;
      }
      dp[column] += dp[column - 1];
      dp[column] %= MOD;
    }
  }
  cout << dp[n] << endl;
  return 0;
}