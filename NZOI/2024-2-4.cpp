#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<pair<int, int>> cities;
vector<int> path;
vector<ll> money;
vector<int> change;

ll cost(int a, int b) {
  ll dx = cities[a].first - cities[b].first;
  ll dy = cities[a].second - cities[b].second;
  return ceil(sqrt(static_cast<double>(dx * dx + dy * dy)));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  cities.resize(n);
  change.resize(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> cities[i].first >> cities[i].second;
  }

  path.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> path[i];
  }

  money.resize(m, 0);
  for (int i = m - 2; i >= 0; i--) {
    money[i] = money[i + 1] + cost(path[i], path[i + 1]);
  }

  for (int i = 0; i < n; i++) {
    int left = 0, right = m;
    while (left != right) {
      int mid = (left + right) / 2;
      if (cost(i, path[mid]) <= money[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    change[left]++;
  }

  int res = n - 1;
  for (int i = 0; i < m; i++) {
    res -= change[i];
    cout << res;
    if (i == m - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }

  return 0;
}