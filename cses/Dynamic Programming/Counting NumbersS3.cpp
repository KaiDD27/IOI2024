// 数位统计 DP 递推实现，不推荐
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int maxN = 20; // a,b最大也就是 19 位数，所以 20 就够用了

vector<bool> limitValid(maxN);
vector<vector<ll>> dp;

ll solve(ll x) {
  if (x == -1)
    return 0;
  if (x == 0)
    return 1;
  fill(limitValid.begin(), limitValid.end(), false);
  vector<int> digit;
  digit.push_back(0);
  for (int i = 0; x > 0; i++) {
    digit.push_back(x % 10);
    x /= 10;
  }

  int N = (int)digit.size() - 1;
  // N 位数，最高位是 N 位，最低位是 1 位，每一个位都有 0-9，共 10 个选择
  dp.clear();
  dp.resize(N + 1, vector<ll>(10));
  // 如果x的前缀位已经出现相邻数相等了则后续所有的数都不合法，也就不需要统计了
  limitValid[N] = true;
  for (int i = N - 1; i > 0; i--)
    limitValid[i] = limitValid[i + 1] && (digit[i] != digit[i + 1]);
  // 最高位对于小于上限的数，其 dp 初始化为 1，也就是有一个有效选择
  // 最高位为0 不能做为有效选择，因为 0如果 x 等于
  // 0，已经在前面直接返回了，前缀位是 0 的情况在后面另外统计了
  for (int d = 1; d < digit[N]; d++)
    dp[N][d] = 1;

  // 统计的主流程，从第二高位递推到个位
  for (int i = N - 1; i > 0; i--) {
    // x前缀位都是合法的情况下，前缀位取值和 x
    // 一样时，当前位不等于前一位的数都是合法的，每一个数都加 1
    if (limitValid[i + 1])
      for (int d = 0; d < digit[i]; d++)
        if (d != digit[i + 1])
          dp[i][d]++;

    // 前缀位全部都是 0 的情况，当前位每一个数都加 1
    for (int d = 1; d <= 9; d++)
      dp[i][d]++;

    // 继承前一位的状态，递推到当前位，当前位不等于前一位的数都是合法的，每一个数都要累计上一位合法的数的数量
    for (int d1 = 0; d1 <= 9; d1++)
      for (int d2 = 0; d2 <= 9; d2++)
        if (d1 != d2)
          dp[i][d2] += dp[i + 1][d1];
  }

  // 全0 是合法的
  ll cnt = 1;
  // x 本身是否合法，如果合法需要加 1
  if (limitValid[1] == true)
    cnt++;
  // 把最低位 0-9 的合法数量累加即可。
  for (int d = 0; d <= 9; d++)
    cnt += dp[1][d];
  return cnt;
}

int main() {
  ll a, b;
  cin >> a >> b;
  // 大的数符合条件的数量减去小数（闭合，所以小的数需要减
  // 1）符合条件的数量
  cout << solve(b) - solve(a - 1) << endl;
}