// 数位统计 DP 预处理递推
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int maxN = 20; // a,b最大也就是 19 位数，所以 20 就够用了
const int leadingZero = 1;
// 第一维表示哪一位（从高到低是 从 N 到 1），第二维这位上面的的数是
// 0-9，第三维0 表示高位不是全部是 0，1 表示高位全是 0
ll dp[maxN][10][2];

void init() { // 预处理
  for (int j = 0; j <= 9; j++) {
    dp[1][j][0] = 1;
  }
  // 预处理为i=2的时候做准备
  dp[1][0][1] = 1;
  for (int i = 2; i <= maxN; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        if (j != k)
          dp[i][j][0] += dp[i - 1][k][0];
      }
    }
    // 前导 0 就是比非前导 0 多了一个第一位的前导0 数量。
    dp[i][0][leadingZero] += dp[i][0][0];
    dp[i][0][leadingZero] += dp[i - 1][0][leadingZero];
  }
}
ll solve(ll num) {
  // 特判当第一个数为 0时，会导致 x==-1，需要返回 0
  if (num == -1)
    return 0;

  ll ans = 0;
  vector<int> digit;
  digit.push_back(0);
  for (int i = 0; num > 0; i++) {
    digit.push_back(num % 10);
    num /= 10;
  }
  digit.push_back(-1);
  digit.push_back(-2);

  // N 位数，最高位是 N 位，最低位是 1 位，每一个位都有 0-9，共 10
  // 个选择，每种选择下满足条件的数量
  // digit的第 0 为是 0，第 N+1是-1,第 N+2位是-2这三个是作为保护墙
  int N = (int)digit.size() - 3;

  // 统计的主流程
  // 从高位往低位处理，最高位时需要考虑前导 0，其他位则不用考虑
  bool limitValid = true;
  for (int i = N; i >= 1; i--) {
    if (digit[i + 1] == digit[i + 2]) {
      limitValid = false;
      break;
    }
    for (int j = 0; j < digit[i]; j++) {
      if (j == digit[i + 1]) {
        continue;
      }
      ans += dp[i][j][0];
      // 最高位要考虑前导0
      if (i == N && j == 0)
        ans += dp[N - 1][0][leadingZero];
    }
  }
  // 如果limit合法，则加上
  if (limitValid == true && digit[1] != digit[2])
    ans++;
  return ans;
}

int main() {
  ll a, b;
  init();
  cin >> a >> b;
  // 大的数符合条件的数量减去小数（闭合，所以小的数需要减
  // 1）符合条件的数量
  cout << solve(b) - solve(a - 1) << endl;
}