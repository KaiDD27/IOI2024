////背包问题+滚动数组优化
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
// 将问题转化从i 个数的选出任意个数，让他们的和为某一个值，有多少种可能性，当
// i 等于n，且和为 n 个数之和的一半的时候，这样的可能性除以 2 就是这题的答案
// 因为最后结果要除以二，模的除法涉及逆元，但是可以通过累计多少个
// MOD 来绕过除法逆元的计算，Pair 中的second元素就是来计算多少个 MOD
// 的，对二求余即可。
vector<pair<int, int>> dp;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  // 如果是是奇数则无法平分，则无解
  int sumN = (1 + n) * n / 2;
  if (sumN % 2 != 0) {
    cout << "0" << endl;
    return 0;
  }
  // 将问题转化从i 个数的选出任意个数，让他们的和为某一个值，有多少种可能性，当
  // i 等于n，且和为 n 个数之和的一半的时候，这样的可能性除以 2 就是这题的答案
  dp.resize(sumN + 1);
  dp[0].first = 1;
  for (int i = 1; i <= n; i++) {
    int sumI = (1 + i) * i / 2;
    for (int j = sumI; j >= 0; j--) {
      // 和大于sum/2的都可以转化为选剩下的那部分
      if (j < sumI / 2) {
        dp[j] = dp[sumI - j];
        continue;
      }
      // 大于和的数都不可能被选中，直接转化为dp[j]
      if (i > j) {
        dp[j] = dp[j];
      } else if (i <= j) {
        pair<int, int> prev = dp[j - i]; // i被选中可能性
        dp[j].first += prev.first;       // 累加i没有被选中可能性

        dp[j].second += (dp[j].first / MOD);
        dp[j].second += prev.second;

        dp[j].first %= MOD;
        dp[j].second %= 2;
      }
    }
  }
  cout << (dp[sumN / 2].first + dp[sumN / 2].second * MOD) / 2 << endl;
  return 0;
}