#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
    return 0;
  }
  if (a > b)
    swap(a, b);
  dp.resize(a + 1, vector<int>(b + 1));
  for (int j = 1; j <= b; j++)
    dp[1][j] = j - 1;

  for (int i = 2; i <= a; i++) {
    for (int j = 1; j <= b; j++) {

      if (i > j)
        dp[i][j] = dp[j][i];
      else if (i < j) {
        // 不需要去想什么巧妙的解法,不要提前剪枝，直接傻瓜式，只要能够缩小范围就行，先解出来，如果超时再考虑剪枝优化之类的
        dp[i][j] = a + b; // 取一个最大值
        for (int m = 1; m < i; m++) {
          dp[i][j] = min(dp[i][j], dp[m][j] + dp[i - m][j] + 1);
        }
        for (int n = 1; n < j; n++) {
          dp[i][j] = min(dp[i][j], dp[i][n] + dp[i][j - n] + 1);
        }
      } else {
        dp[i][j] = 0;
      }
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}