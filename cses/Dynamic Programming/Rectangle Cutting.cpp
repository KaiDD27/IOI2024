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
  // 行小于列，可以便于后面剪枝,如果不剪枝则非必需
  if (a > b)
    swap(a, b);
  // 当做是 1-base 的来用
  dp.resize(a + 1, vector<int>(b + 1));

  for (int iA = 1; iA <= a; iA++) {
    for (int jB = 1; jB <= b; jB++) {
      // 因为 a小于 b，所以可以确保 dp[j][i]
      // 已经被计算过了。不做这个优化也满足时间复杂度
      if (iA > jB)
        dp[iA][jB] = dp[jB][iA];
      else if (iA < jB) {
        // 如果想不出什么巧妙的解法，那可能就是没有巧妙的解法，考虑到a,b范围这么小，直接傻瓜式，
        // 只要能够缩小范围就行，先解出来，如果超时再考虑剪枝优化之类的
        // 完全递归的思想，没有任何可以优化的思路
        dp[iA][jB] = a - 1 + b - 1; // 取一个最大值，分割为 1*1的方块
        for (int m = 1; m < iA; m++) {
          dp[iA][jB] = min(dp[iA][jB], dp[m][jB] + dp[iA - m][jB] + 1);
        }
        for (int n = 1; n < jB; n++) {
          dp[iA][jB] = min(dp[iA][jB], dp[iA][n] + dp[iA][jB - n] + 1);
        }
      } else {
        dp[iA][jB] = 0;
      }
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}