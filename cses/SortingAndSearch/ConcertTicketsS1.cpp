#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<int> t;
vector<int>
    h; // 每次都要erase所以空间复杂度不满足，因为每次erase都是O(n),整体就是
       // O(n2)了
int main() {
  int n, m;
  cin >> n >> m;
  h.resize(n);
  t.resize(m);
  for (auto &i : h)
    cin >> i;
  for (auto &i : t)
    cin >> i;
  sort(h.begin(), h.end());
  for (auto i : t) {
    if (h.empty()) {
      cout << -1 << endl;
      continue;
    }
    auto it = upper_bound(h.begin(), h.end(), i);
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