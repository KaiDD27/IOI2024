#include <iostream>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;
#define endl '\n'
int t[200100];
set<pair<int, int>> h;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    h.emplace(tmp, i);
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    if (h.empty()) {
      cout << -1 << endl;
      continue;
    }
    auto it = h.upper_bound(make_pair(t[i], 200100));
    if (it != h.begin()) {
      --it;
      cout << it->first << endl;
      h.erase(it);
    } else {
      cout << -1 << endl;
    }
  }
}