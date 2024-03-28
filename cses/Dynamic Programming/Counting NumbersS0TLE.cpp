// 暴力递归
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll count(vector<int> &digit, int pos, int prev, int leadingZero, int limit) {
  if (pos == 0)
    return 1;

  int end = -1;
  if (limit == true) {
    end = digit[pos];
  } else {
    end = 9;
  }
  ll ans = 0;
  for (int i = 0; i <= end; i++) {
    if ((i == 0 && leadingZero == 1) || i != prev)
      ans += count(digit, pos - 1, i, leadingZero && (i == 0),
                   limit && (i == end));
  }

  return ans;
}

ll solve(ll num) {
  if (num == -1)
    return 0;

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