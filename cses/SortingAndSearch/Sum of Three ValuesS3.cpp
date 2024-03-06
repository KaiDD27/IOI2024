#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, int>> a;
multimap<ll, int> mmpA;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  mmpA.insert({a.rbegin()->first, a.rbegin()->second});
  for (int i = n - 3; i >= 0; i--) {
    mmpA.insert({a[i + 1].first, a[i + 1].second});
    for (int j = i + 1; j < n - 1 && a[i].first + a[j].first < x; j++) {
      auto range = mmpA.equal_range(x - a[i].first - a[j].first);
      for (auto r = range.first; r != range.second; r++) {
        if (r->second != a[j].second) {
          cout << a[i].second << " " << a[j].second << " " << r->second << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}