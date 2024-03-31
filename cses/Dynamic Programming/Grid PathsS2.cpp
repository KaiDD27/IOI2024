// 递推
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<vector<int>> dp;
vector<vector<bool>> gridAvailable;
ll dfs(int line, int column) {
  if (line <= 0 || column <= 0 || gridAvailable[line][column] == false)
    return 0;
  if (line == 1 && column == 1)
    return 1;
  if (dp[line][column] != -1)
    return dp[line][column];
  return dp[line][column] =
             (dfs(line - 1, column) + dfs(line, column - 1)) % MOD;
}
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
  dp.resize(n + 1, vector<int>(n + 1, 0));
  if (gridAvailable[1][1] == true && gridAvailable[n][n] == true)
    dp[1][1] = 1;
  else {
    cout << 0 << endl;
    return 0;
  }
  for (int line = 1; line <= n; line++) {
    for (int column = 1; column <= n; column++) {
      if (gridAvailable[line][column] == false)
        continue;
      // 对于dp[1][1]来说初始值是 1，其余的是 0
      dp[line][column] += (dp[line - 1][column] + dp[line][column - 1]);
      dp[line][column] %= MOD;
    }
  }
  cout << dp[n][n] << endl;
  return 0;
}