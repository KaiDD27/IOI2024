// 熟悉二进制，熟悉异或，熟悉bitset
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int popcount(ll x) {
  int cnt = 0;
  while (x != 0) {
    if (x & 1)
      cnt++;
    // x = x >> 1;
    x /= 2;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int a, b;
  ll numC;
  cin >> a >> b >> numC;
  int c = popcount(numC);
  // 通过穷举各种数据来分析所有非法的结果
  if ((c > a + b) || (c > 60 - a + 60 - b) || abs(a - b) > c ||
      ((a + b - c) % 2 == 1)) {
    cout << -1 << endl;
    return 0;
  }
  bitset<60> x, y, bitsetNumC(numC);

  int d = (a + b - c) / 2;
  int bothOne = d;
  for (int i = 0; i < 60; i++) {
    if (bitsetNumC[i] == 1) {
      if (a - d > 0) {
        x[i] = 1;
        y[i] = 0;
        a--;
      } else if (b - d > 0) {
        x[i] = 0;
        y[i] = 1;
        b--;
      }
    } else {
      if (bothOne) {
        x[i] = 1;
        y[i] = 1;
        bothOne--;
      } else {
        x[i] = 0;
        y[i] = 0;
      }
    }
  }
  cout << x.to_ullong() << " " << y.to_ullong() << endl;
  return 0;
}