// 递推，不推荐
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp;
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

  // dp[0]空着不用，方便对齐 1 base,全部初始化为 1
  dp.resize(n + 1, 1);
  // 处理最后一行，倒序，一旦出现一个格子不可用，则从这个格子开始倒序的格子都是不可用了。
  for (int i = n, isZero = 0; i >= 1; i--) {
    if (gridAvailable[n][i] == false)
      isZero = 1;
    if (isZero == 1)
      dp[i] = 0;
  }

  for (int y = n - 1; y >= 1; y--) {
    if (gridAvailable[y][n] == false)
      dp[n] = 0;
    for (int x = n - 1; x >= 1; x--) {
      if (gridAvailable[y][x] == false) {
        dp[x] = 0;
        continue;
      }
      // 看往下走的如果为false则清空，否则则继承下一行相同列的值
      if (gridAvailable[y + 1][x] == false)
        dp[x] = 0;
      else {
        dp[x] = dp[x];
      }
      // 看往右走的情况
      if (gridAvailable[y][x + 1] == true) {
        dp[x] += dp[x + 1];
        dp[x] %= (int)(1e9 + 7);
      }
    }
  }
  cout << dp[1] << endl;
  return 0;
}