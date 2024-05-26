#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, k;
vector<ll> w;
vector<ll> rowGap;
map<ll, ll> mpWidth;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> k;
  w.resize(n);
  for (auto &wi : w)
    cin >> wi;
  // 大于等于 1 小于等于下一个 mp key 的都可以放在第1层.
  mpWidth[1] = 1;
  // 1-base,0做为墙
  rowGap.push_back(0);
  for (auto wi : w) {
    // 小于等于 wi
    ll layerToPack = prev(mpWidth.upper_bound(wi))->second;
    if (layerToPack == rowGap.size())
      rowGap.push_back(k - wi);
    else
      rowGap[layerToPack] -= wi;
    // 看看是否需要更新 map
    if (prev(mpWidth.upper_bound(rowGap[layerToPack] + 1))->second <
        layerToPack + 1) {
      mpWidth[rowGap[layerToPack] + 1] = layerToPack + 1;
      auto it = mpWidth.find(rowGap[layerToPack] + 1);
      while (next(it) != mpWidth.end() && next(it)->second <= layerToPack + 1)
        mpWidth.erase(next(it));
    }
  }
  cout << rowGap.size() - 1 << endl;
  return 0;
}