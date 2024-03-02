#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, ll>> a; // first是值，second 是 position
vector<array<ll, 3>> sumOfTwo;
map<ll, ll> mpSumToIdx;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, x;
  cin >> n >> x;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ll tmp = a[i].first + a[j].first;
      if (tmp < x) {
        sumOfTwo.push_back({tmp, a[i].second, a[j].second});
      }
    }
  }

  /*
  for (int i = 1; i <= n; i++) {
    if (a[i] > x - 2)
      continue;
    auto range = mpAtoPos.equal_range(x - a[i]);
    for (auto j = range.first; j != range.second;) {
      if (j->second.first != i && j->second.second != i) {
        cout << i << " " << j->second.first << " " << j->second.second << endl;
        return 0;
      } else {
        ++j; // 移动到下一个键值对
      }
    }
  }*/
  cout << "IMPOSSIBLE" << endl;
  return 0;
}