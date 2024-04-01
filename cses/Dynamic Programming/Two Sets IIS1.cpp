// 转化为背包问题 记忆化搜索
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int n;
// 将问题转化从i 个数的选出任意个数，让他们的和为某一个值，有多少种可能性，当
// i 等于n，且和为 n 个数之和的一半的时候，这样的可能性除以 2 就是这题的答案
// 因为最后结果要除以二，模的除法涉及逆元，但是可以通过累计多少个
// MOD 来绕过除法逆元的计算，Pair 中的second元素就是来计算多少个 MOD
// 的，对二求余即可。
vector<vector<pair<int, int>>> dp;

pair<int, int> dfs(int i, int j) {
  if (i == 0) {
    return j == 0 ? pair<int, int>(1, 0) : pair<int, int>(0, 0);
  }
  if (dp[i][j].first != -1) {
    return dp[i][j];
  }
  pair<int, int> res = dfs(i - 1, j);
  if (j >= i) {
    pair<int, int> tmp = dfs(i - 1, j - i);
    res.first += tmp.first;

    res.second += (res.first / MOD);
    res.second += tmp.second;

    res.first %= MOD;
    res.second %= 2;
  }
  return dp[i][j] = res;
}

int main() {
  cin >> n;
  int sumN = n * (n + 1) / 2;
  if (sumN % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  sumN /= 2;
  dp.resize(n + 1, vector<pair<int, int>>(sumN + 1, {-1, 0}));
  pair<int, int> ans = dfs(n, sumN);
  cout << (ans.first + ans.second * MOD) / 2 << endl;
  return 0;
}