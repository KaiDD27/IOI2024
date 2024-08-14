#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

// 计算最大公约数（GCD）
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// 计算最小公倍数（LCM）
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  // Ensure a is always the smaller value
  if (a > b)
    swap(a, b);

  // Initialize the best solution: {difference from target, number of boxes}
  pair<ll, ll> best = {k, 0};

  ll miniMultiple = lcm(a, b); // 计算 a 和 b 的最小公倍数

  // Iterate through possible numbers of 'a' boxes
  for (int ai = 0; ai < miniMultiple / a; ai++) {
    ll remain = k - ai * a;
    if (remain > 0) {
      best = min(best, {remain % b, ai + remain / b});
      best = min(best, {b - remain % b, ai + remain / b + 1});
    } else {
      best = min(best, {-remain, ai});
    }
  }

  // Output the best solution: difference from target and number of boxes
  cout << best.first << " " << best.second << endl;
}