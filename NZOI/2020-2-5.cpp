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
    auto it = mpWidth.upper_bound(wi);
    ll layerToPack = prev(it)->second;
    if (it == mpWidth.end())
      rowGap.push_back(k - wi);
    else
      rowGap[layerToPack] -= wi;
    // 如果以前这么长的 box 是可以放到更低的层的，则需要修改下
    if (prev(mpWidth.upper_bound(rowGap[layerToPack] + 1))->second <=
        layerToPack) {
      mpWidth[rowGap[layerToPack] + 1] = layerToPack + 1;
      auto it = mpWidth.find(rowGap[layerToPack] + 1);
      // 如果是当前长的 box，且放的层小于等于当前，这明显是不合理的，应该删除
      while (next(it) != mpWidth.end() && next(it)->second <= layerToPack + 1)
        mpWidth.erase(next(it));
    }
  }
  // 1-base
  cout << rowGap.size() - 1 << endl;
  return 0;
}