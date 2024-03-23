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
  dp.resize(1 << n, {n, x}); // 最大值是n+1个电梯，且装满了x
  dp[0] = {1, 0};
  for (int iMask = 1; iMask < dp.size(); iMask++) {
    // 用最笨的方法遍历所有的先后次序，则一定可以找到最优解，最优解就是在一个组合里面最少的电梯趟数且最后一个电梯重量最小
    // 最后一个上电梯的人，可能是任何一个人，所有的情况都要考虑，取最小值
    // 在某一个iMask组合下，最后任何一个组合里面的人都可能是最后一个上电梯的人，所有都要考虑，取最小值即可
    // 巧妙的利用了二进制递推时，大的数总是任何位上面的 1 变成 0
    // 都可以在前面找到，这样确保了转移总是从未知向已知转移
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