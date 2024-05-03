#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <regex>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> a, b;
map<ll, ll> mpGap;
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
  ll maxSameDate = 0;
  for (int ai = 0; ai < n; ai++) {
    for (int bi = 0; bi < n; bi++) {
      mpGap[a[ai] - (b[bi] + bOffset)]++;
    }
  }
  for (auto mi : mpGap)
    maxSameDate = max(maxSameDate, mi.second);

  cout << n * 2 - maxSameDate << endl;
  return 0;
}