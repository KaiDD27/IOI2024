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
map<ll, ll> mpGap;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> k;
  w.resize(n);
  for (auto &wi : w)
    cin >> wi;
  mpGap[0] = 0;
  rowGap.push_back(0);
  for (auto wi : w) {
    auto it = mpGap.lower_bound(wi);
    ll layerToPack = prev(it)->second + 1;
    if (it == mpGap.end()) {
      rowGap.push_back(k - wi);
    } else {
      rowGap[layerToPack] -= wi;
    }
    if (it == mpGap.end() || rowGap[layerToPack] < it->first) {
      mpGap[rowGap[layerToPack]] = layerToPack;
      while (prev(it)->first != rowGap[layerToPack])
        mpGap.erase(prev(it));
    }
    if (it != mpGap.end() && layerToPack == it->second) {
      mpGap.erase(it);
    }
  }
  cout << rowGap.size() - 1 << endl;
  return 0;
}