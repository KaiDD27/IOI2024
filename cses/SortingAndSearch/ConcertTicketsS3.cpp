#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<int> t;
multiset<ll> h;
int main() {
  int n, m;
  cin >> n >> m;
  t.resize(m);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    h.insert(tmp);
  }
  for (auto &i : t)
    cin >> i;
  for (auto i : t) {
    if (h.empty()) {
      cout << -1 << endl;
      continue;
    }
    auto it = h.upper_bound(i);
    if (it != h.begin()) {
      --it;
      cout << *it << endl;
      h.erase(it);
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}