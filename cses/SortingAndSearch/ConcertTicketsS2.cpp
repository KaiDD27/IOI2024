#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<int> t;
set<pair<int, int>> h;

int main() {
  int n, m;
  cin >> n >> m;
  t.resize(m);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    h.insert({tmp, i});
  }
  for (auto &i : t)
    cin >> i;
  for (auto i : t) {
    if (h.empty()) {
      cout << -1 << endl;
      continue;
    }
    auto it = h.upper_bound({i, n});
    if (it != h.begin()) {
      --it;
      cout << it->first << endl;
      h.erase(it);
    } else {
      cout << -1 << endl;
    }
  }
}