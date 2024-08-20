#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<pair<ll, ll>> cities;
vector<ll> path;
vector<ll> money;
vector<ll> xValues;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;
  cities.resize(N);
  xValues.resize(N);
  for (auto &city : cities) {
    cin >> city.first >> city.second;
    if (city.second != 0)
      return 0;
  }
  for (ll i = 0; i < N; i++) {
    xValues[i] = cities[i].first;
  }
  sort(xValues.begin(), xValues.end());
  path.resize(M);
  for (auto &pi : path) {
    cin >> pi;
  }

  money.resize(M, 0);
  for (int i = M - 2; i >= 0; i--) {
    money[i] =
        money[i + 1] + abs(cities[path[i]].first - cities[path[i + 1]].first);
  }

  for (ll i = 0; i < M - 1; i++) {
    // 计算当前城市可以到达的范围
    ll left = cities[path[i]].first - money[i];
    ll right = cities[path[i]].first + money[i];

    // 使用二分查找找到范围内的城市数量
    auto low = lower_bound(xValues.begin(), xValues.end(), left);
    auto up = upper_bound(xValues.begin(), xValues.end(), right);

    // 输出范围内的城市数量（不包括当前城市）
    cout << distance(low, up) - 1 << " ";
  }
  cout << 0 << endl;
  return 0;
}