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
  b.push_back(0);
  for (auto &si : s)
    cin >> si;
  ll minBP = 100000, maxSP = 1;
  for (int i = 1; i < n - 1; i++) {
    minBP = min(minBP, b[i]);
    maxSP = max(maxSP, s[i]);
    if (minBP < maxSP && b[i + 1] < maxSP) {
      c += ((c / minBP) * (maxSP - minBP));
      minBP = b[i + 1];
      maxSP = 1;
    }
  }
  cout << c << endl;
  return 0;
}