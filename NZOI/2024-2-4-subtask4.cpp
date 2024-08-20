#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

const int MAX_COORD = 500;
const int MAX_COST = 708;

vector<pair<ll, ll>> cities;
vector<int> stops;
unordered_set<int> unreachable;
vector<int> answers;

int distance(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  ll dx = a.first - b.first;
  ll dy = a.second - b.second;
  return ceil(sqrtl(dx * dx + dy * dy));
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  int n, m;
  cin >> n >> m;

  cities.resize(n);
  for (auto &city : cities) {
    cin >> city.first >> city.second;
  }

  stops.resize(m);
  for (auto &stop : stops) {
    cin >> stop;
  }

  for (int i = 0; i < n; i++) {
    unreachable.insert(i);
  }

  answers.resize(m);
  int money = 0;

  for (int i = m - 1; i >= 0; i--) {
    int current_city = stops[i];
    unreachable.erase(current_city);

    for (auto it = unreachable.begin(); it != unreachable.end();) {
      int city = *it;
      int cost = distance(cities[current_city], cities[city]);
      if (cost <= money) {
        it = unreachable.erase(it);
      } else {
        ++it;
      }
    }

    answers[i] = n - unreachable.size() - 1;

    if (i > 0) {
      money += distance(cities[stops[i]], cities[stops[i - 1]]);
      if (money >= MAX_COST) {
        fill(answers.begin(), answers.begin() + i, n - 1);
        // Note: answers.begin() + i is an open interval (不包括i)
        // 如果需要包括i，应该使用 answers.begin() + i + 1
        break;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cout << answers[i];
    if (i == m - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }

  return 0;
}