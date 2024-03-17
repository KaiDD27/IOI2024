#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> w;
vector<pair<int, int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  w.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  dp.resize(1 << n, {n + 1, x + 1});
  dp[0] = {1, 0};
  for (int iMask = 1; iMask < dp.size(); iMask++) {
    // 用最笨的方法遍历所有的先后次序，则一定可以找到最优解，最优解就是在一个组合里面最少的电梯趟数且最后一个电梯的最大剩余重量
    for (int i = 1; i <= n; i++) {
      if (iMask & 1 << (i - 1)) // 说明第 i 个人在这个组合里面
      {
        auto prev = dp[iMask & ~(1 << (i - 1))]; // 去掉第 i 个人的组合
        if (prev.second + w[i] > x) {            // 装不下则新开趟电梯
          dp[iMask] = min(dp[iMask], {prev.first + 1, w[i]});
        } else {
          dp[iMask] = min(dp[iMask], {prev.first, prev.second + w[i]});
        }
      }
    }
  }
  cout << dp[(1 << n) - 1].first << endl;
  return 0;
}