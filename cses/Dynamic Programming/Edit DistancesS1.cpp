// 递推
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  string strN, strM;
  cin >> strN >> strM;
  n = strN.size(), m = strM.size();
  // dp的行为第一个字符串的长度，列为第二个字符串的长度
  // 由于每一个格子的结果只与上一行左边相关，所以只用一行就可以了。
  dp.resize(n + 1, vector<int>(m + 1));

  // 第 0 行初始化
  for (int column = 0; column <= m; column++)
    dp[0][column] = column;
  // 第 0 列初始化
  for (int line = 0; line <= n; line++)
    dp[line][0] = line;
  for (int line = 1; line <= n; line++) {
    for (int column = 1; column <= m; column++) {
      // strN和strM都是0-base的
      if (strN[line - 1] == strM[column - 1])
        dp[line][column] = dp[line - 1][column - 1];
      else // 不相等，则为三种结果中的最小的那个加1，动态规划就是要老老实实的从初始状态递推到最终状态
        dp[line][column] =
            min(dp[line - 1][column - 1],
                min(dp[line - 1][column], dp[line][column - 1])) +
            1;
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
/*这道题的这个解法不会遗漏最优解，这个结论可以通过数学归纳法来证明边界情况:
当字符串长度为0或1时,从头开始递推显然可以得到最优解。
假设当字符串长度≤k时,从头开始递推可以得到最优解。现在考虑字符串长度为k+1的情况。
设A[1:k+1]和B[1:k+1]为两个长度为k+1的字符串。要将A转换为B,可以这样做:
先将A[1:k]转换为B[1:k],根据假设,从头开始递推可以得到这一步的最优解,设代价为dp[k][k]。
然后将A[k+1]转换为B[k+1],代价为0或1。
所以将A[1:k+1]转换为B[1:k+1]的最小代价为dp[k][k]+0或1。
而从头开始递推得到的dp[k+1][k+1]正是上述最小代价。因为dp[k+1][k+1]是通过dp[k][k]、dp[k+1][k]和dp[k][k+1]三者的最小值转移得到的。
由数学归纳法可知,从头开始递推可以得到任意长度字符串的最优解。，*/