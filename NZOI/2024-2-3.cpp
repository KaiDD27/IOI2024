#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
using namespace std;
#define ll long long
int N;
ll A;
map<ll, vector<pair<ll, int>>> rows;
int main() {
  cin >> N >> A;
  for (int i = 0; i < N; i++) {
    ll r, c;
    cin >> r >> c;
    for (ll ri = max(0LL, r - A); ri < r + A + 1; ri++) {
      rows[ri].push_back({max(0LL, c - A), 1});
      rows[ri].push_back({c + A + 1, -1});
    }
  }
  ll res = 0;
  for (auto row : rows) {
    sort(row.second.begin(), row.second.end());
    int cnt = 0;
    ll prev = 0;
    for (auto cur : row.second) {
      if (cnt > 0) {
        res += cur.first - prev;
      }
      cnt += cur.second;
      prev = cur.first;
    }
  }
  cout << res;
}