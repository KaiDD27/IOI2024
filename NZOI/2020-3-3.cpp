#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, c;
vector<ll> b, s;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> c;
  b.resize(n);
  s.resize(n);
  for (auto &bi : b)
    cin >> bi;
  for (auto &si : s)
    cin >> si;
  ll minBP = 100000;
  //
  for (int i = 0; i < n; i++) {
    minBP = min(minBP, b[i]);
    // 虚拟卖出，先把可能的收益统计上，当后续 minBP
    // 取到更小的值时，之前的一步就是真正卖出的时候
    if (minBP < s[i]) {
      c += ((c / minBP) * (s[i] - minBP));
      minBP = s[i];
    }
  }
  cout << c << endl;
  return 0;
}