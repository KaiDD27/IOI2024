#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, int>> a;
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
    for (int j = i + 1; j < n && a[i].first + a[j].first < x; j++) {
      int k = lower_bound(a.begin() + j + 1, a.end(),
                          make_pair(x - a[i].first - a[j].first, 0)) -
              a.begin();
      if (k == n || a[i].first + a[j].first + a[k].first != x)
        continue;
      else {
        cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}