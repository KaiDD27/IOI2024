#include <algorithm>
#include <array>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> a, b;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll bOffset = a[0] - b[n - 1];
  ll maxSameDate = 1;
  while (b[0] + bOffset < a[n - 1]) {
    auto itB = lower_bound(b.begin(), b.end(), a[0] - bOffset);
    if (itB != b.begin())
      itB--;
    ll minGap = 1e9 + 10;
    while (1) {
      auto itA = upper_bound(a.begin(), a.end(), *itB + bOffset);
      if (itA == a.end())
        break;
      minGap = min(minGap, *itA - (*itB + bOffset));
      if (minGap == 1)
        break;
      itB++;

      if (itB == b.end()) {
        break;
      }
    }
    bOffset += minGap;
    ll sameDateCnt = 0;
    for (ll ai = 0, bi = 0; ai <= n - 1 && bi <= n - 1;) {
      if (b[bi] + bOffset < a[ai])
        bi++;
      else if (b[bi] + bOffset > a[ai])
        ai++;
      else if (b[bi] + bOffset == a[ai]) {
        sameDateCnt++;
        ai++;
        bi++;
      }
    }
    maxSameDate = max(maxSameDate, sameDateCnt);
  }
  cout << n * 2 - maxSameDate << endl;
  return 0;
}