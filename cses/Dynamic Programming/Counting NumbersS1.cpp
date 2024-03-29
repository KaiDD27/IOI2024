// 数位统计 DP 的记忆化搜索实现
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxN = 20; // a,b最大也就是 19 位数，所以 20 就够用了
// 位数，prev往上一位的数字，leadingZero，limit
ll dp[maxN][10][2][2];

ll count(vector<int> &digit, int pos, int prev, int leadingZero, int limit) {
  if (pos == 0)
    return 1;
  if (dp[pos][prev][leadingZero][limit] != -1)
    return dp[pos][prev][leadingZero][limit];

  int len = -1;
  if (limit == true) {
    len = digit[pos];
  } else {
    len = 9;
  }
  ll ans = 0;
  for (int i = 0; i <= len; i++) {
    if ((i == 0 && leadingZero == 1) || i != prev)
      ans += count(digit, pos - 1, i, leadingZero && (i == 0),
                   limit && (i == len));
  }
  dp[pos][prev][leadingZero][limit] = ans;
  return ans;
}

ll solve(ll num) {
  if (num == -1)
    return 0;
  memset(dp, -1, sizeof(dp));
  vector<int> digit;
  digit.push_back(0);
  for (int i = 0; num > 0; i++) {
    digit.push_back(num % 10);
    num /= 10;
  }
  return count(digit, digit.size() - 1, 0, 1, 1);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << endl;
  return 0;
}