#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<pair<ll, ll>> cities;
vector<int> path;
vector<int> money;
vector<int> answers;

int distanceAB(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  ll dx = a.first - b.first;
  ll dy = a.second - b.second;
  // 这行代码计算两个城市之间的欧几里得距离
  // dx * dx + dy * dy 计算距离的平方
  // sqrtl 计算平方根，得到实际距离
  // ceill 向上取整，确保距离是整数
  // 返回值是两个城市之间的距离（整数）
  return ceill(sqrtl(dx * dx + dy * dy));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  cities.resize(N);
  for (auto &city : cities) {
    cin >> city.first >> city.second;
  }
  path.resize(M);
  for (auto &pi : path) {
    cin >> pi;
  }

  money.resize(M, 0);
  for (int i = M - 2; i >= 0; i--) {
    money[i] = money[i + 1] + distanceAB(cities[path[i]], cities[path[i + 1]]);
  }

  answers.resize(M);

  if (N <= 500 || M <= 500) {
    for (int i = 0; i < M - 1; i++) {
      int count = 0;
      for (int j = 0; j < N; j++) {
        if (j == path[i])
          continue;
        if (distanceAB(cities[path[i]], cities[j]) <= money[i])
          count++;
      }
      answers[i] = count;
    }
  } else {
    return 0;
  }

  for (int i = 0; i < M; i++) {
    cout << answers[i] << ' ';
  }
  return 0;
}