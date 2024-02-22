#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'
ll t[200100];
multiset<ll> h;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    h.emplace(tmp);
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    if (h.empty()) {
      cout << -1 << endl;
      continue;
    }
    auto it = h.upper_bound(t[i]);
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