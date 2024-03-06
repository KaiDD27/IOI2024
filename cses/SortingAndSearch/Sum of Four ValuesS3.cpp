#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, int>> a;
multimap<ll, pair<int, int>> mmpA;
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
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      mmpA.insert({a[i].first + a[j].first, {a[i].second, a[j].second}});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll current_sum = a[i].first + a[j].first;
      auto range = mmpA.equal_range(x - current_sum);
      for (auto r = range.first; r != range.second; r++) {
        if (r->second.first != a[i].second && r->second.second != a[i].second &&
            r->second.first != a[j].second && r->second.second != a[j].second) {
          cout << a[i].second << " " << a[j].second << " " << r->second.first
               << " " << r->second.second << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}