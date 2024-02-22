#include <iostream>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  cout << 0 << endl;
  for (ll k = 2; k <= n; k++) {
    // 用总数减去冲突的，而且冲突的情况分为横跳 和 竖跳 两种情况
    cout << (k * k * (k * k - 1)) / 2 - 4 * (k - 1) * (k - 2) << endl;
  }
  return 0;
}