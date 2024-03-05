#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<pair<int, int>> a;
int main() {
  int n, x;
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  for (int l = 0, r = n - 1; l < r;) {
    if (a[l].first + a[r].first == x) {
      cout << a[l].second << " " << a[r].second << endl;
      return 0;
    }
    if ((a[l].first + a[r].first > x)) {
      r--;
    } else {
      l++;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}