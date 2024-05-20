#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n, t;
vector<int> h;
vector<int> vt;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> t;
  h.resize(n);
  for (auto &hi : h)
    cin >> hi;
  vt.resize(t);
  for (int i = 0; i < t; i++)
    vt[i] = -(i + 1);
  set<int> setT(vt.begin(), vt.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans == t)
      break;
    // 对于 set,multiset,map,multimap来说，一定要优先使用容器自带的
    // lower_bound，而不是用通用的 lower_bound函数，因为性能好很多
    auto it = setT.lower_bound(-h[i]);
    if (it == setT.end())
      continue;
    setT.erase(it);
    ans++;
  }
  cout << ans << endl;
  return 0;
}