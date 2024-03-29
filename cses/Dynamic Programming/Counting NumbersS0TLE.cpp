// 暴力递归需要关注
// 1.上界限制 2.高位枚举0 3.前导 0
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll count(vector<int> &digit, int pos, int prev, int leadingZero, int limit) {
  if (pos == 0)
    return 1;
  // 上界限制
  int len = -1;
  if (limit == true) {
    len = digit[pos];
  } else {
    len = 9;
  }
  ll ans = 0;
  // 高位枚举0
  for (int i = 0; i <= len; i++) {
    // 前导0
    if ((i == 0 && leadingZero == 1) || i != prev)
      ans += count(digit, pos - 1, i, leadingZero && (i == 0),
                   limit && (i == len));
  }
  return ans;
}

ll solve(ll num) {
  if (num == -1)
    return 0;
  vector<int> digit;
  digit.push_back(0); // 0下标占位
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