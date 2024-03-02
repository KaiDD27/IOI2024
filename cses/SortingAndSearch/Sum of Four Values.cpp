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
  for (int i = 0; i < n - 3 && a[i].first < x - 2; i++) {
    for (int j = i + 1; j < n - 2 && a[i].first + a[j].first < x - 1; j++) {
      int l = j + 1, r = n - 1;
      while (l < r) {
        ll sum = a[i].first + a[j].first + a[l].first + a[r].first;
        if (sum == x) {
          cout << a[i].second << " " << a[j].second << " " << a[l].second << " "
               << a[r].second << endl;
          return 0;
        } else if (sum > x) {
          r--;
        } else {
          l++;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}