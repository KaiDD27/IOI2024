#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  string strN, strM;
  cin >> strN >> strM;
  n = strN.size(), m = strM.size();
  // dp的行为第一个字符串的长度，列为第二个字符串的长度
  // 由于每一个格子的结果只与上一行左边相关，所以只用一行就可以了。
  dp.resize(m + 1);
  for (int j = 0; j <= m; j++)
    dp[j] = j;

  for (int i = 1; i <= n; i++) {
    int up = dp[0];
    // 第一个string 长度为i，第二个string 长度为 0时，需要删除i个 char
    // 才可以转换成功
    dp[0] = i;
    for (int j = 1, leftUp = up; j <= m; j++) {
      up = dp[j];
      // strN和strM都是0-base的
      if (strN[i - 1] == strM[j - 1])
        dp[j] = leftUp;
      else // 不相等，则为三种结果中的最小的那个加1，动态规划就是要老老实实的从初始状态递推到最终状态
        dp[j] = min(leftUp, min(up, dp[j - 1])) + 1;
      // 为下一列做准备
      leftUp = up;
    }
  }
  cout << dp[m] << endl;
  return 0;
}