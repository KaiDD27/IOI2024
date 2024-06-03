#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<char, ll>> queryM;
set<ll> stNoOfficial;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, m;
  cin >> n >> m;
  queryM.resize(m);
  for (auto &[chM, idx] : queryM) {
    cin >> chM >> idx;
    // subtask5会超时，所以直接 return 退出好了。
    if (chM == 'o' && idx > 50050 && m > 500)
      return 0;
  }

  for (auto [chM, idx] : queryM) {
    // 如果 m>500,则大于 50050 不处理了，这样可以解决subtask2，3
    if (chM == 't' && (idx <= 50050 || m <= 500)) {
      if (stNoOfficial.count(idx)) {
        stNoOfficial.erase(idx);
      } else {
        stNoOfficial.insert(idx);
      }
    }
    if (chM == 'o') {
      if (stNoOfficial.count(idx))
        cout << "UNOFFICIAL" << endl;
      else {
        auto it = stNoOfficial.upper_bound(idx);
        cout << idx - stNoOfficial.size() + distance(it, stNoOfficial.end())
             << endl;
      }
    }
  }
  return 0;
}