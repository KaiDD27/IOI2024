// 参见《算法竞赛》上册例5.8
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<vector<int>> dp;
int now, old; // 滚动数组，now指向新的一行，old指向旧的一行
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  if (m > n)
    swap(n, m); // 复杂度O(nm*2^m), m较小有利
  dp.resize(2, vector<int>(1 << m));
  now = 0, old = 1; // 滚动数组
  //-1 行只有一种填充方式，就是全部填满
  dp[now][(1 << m) - 1] = 1;
  // i行j列代表当前格，需要决策是不放还是横放还是竖放，但长条占的位置都不能超过当前格
  for (int i = 0; i < n; i++)     // n行
    for (int j = 0; j < m; j++) { // m列
      // 滚动数组，now始终指向当前的轮廓线，old是上一轮的轮廓线，也就是往左移动一格的轮廓线
      swap(now, old);
      fill(dp[now].begin(), dp[now].end(), 0);
      // 轮廓线是当前格往前数 m 个格子的集合,表示为iMask
      //  遍历轮廓线上所有的掩码，每一位0 代表空，1 代表已填充,最低位（第 0
      //  位）是 当前格往前数一格，最高位（第m-1位）是当前格正上方的格
      // ^这个符号是会改变左侧变量的值的，使用时需要慎重，而&和｜是不会改变左侧变量的值
      for (int iMask = 0; iMask < (1 << m); iMask++) { // iMask：
        // 如果当前格不放，则要求iMask的第m-1 位必须为 1，则否则非法
        if (iMask & 1 << (m - 1)) {
          dp[now][(iMask << 1) & (~(1 << m))] += dp[old][iMask];
          dp[now][(iMask << 1) & (~(1 << m))] %= MOD;
        }
        // 如果当前格竖放，且第 m-1位必须为 0,且i不为第 0 行
        if (i && !(iMask & 1 << (m - 1))) {
          dp[now][(iMask << 1) | 1] += dp[old][iMask];
          dp[now][(iMask << 1) | 1] %= MOD;
        }
        // 如果当前格横放，则要求j不是第0列，且iMask的第 0 位必须为
        // 0，且第 n-1位必须为 1
        if (j && (!(iMask & 1)) && (iMask & 1 << (m - 1))) {
          dp[now][((iMask << 1) | 3) & (~(1 << m))] += dp[old][iMask];
          dp[now][((iMask << 1) | 3) & (~(1 << m))] %= MOD;
          // iMask末尾置为11，且原来的m-1移到了第m位，置0
        }
      }
    }
  cout << dp[now][(1 << m) - 1] << endl;
  return 0;
}
