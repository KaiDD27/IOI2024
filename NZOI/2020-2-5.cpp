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
    ll layerToPack = --it->second + 1;
    if (layerToPack == rowGap.size()) {
      rowGap.push_back(k - wi);
      mpGap[k - wi] = rowGap.size() - 1;
      while (prev(it)->first != k - wi)
        mpGap.erase(prev(it));
    } else {
      rowGap[layerToPack] -= wi;
      if (layerToPack == it->second) {
        mpGap[rowGap[layerToPack]] = layerToPack;
        while (prev(it)->first != rowGap[layerToPack])
          mpGap.erase(prev(it));
        mpGap.erase(it);
      } else if (rowGap[layerToPack] < it->first) {
        mpGap[rowGap[layerToPack]] = layerToPack;
        while (prev(it)->first != rowGap[layerToPack])
          mpGap.erase(prev(it));
      }
    }
  }
  cout << rowGap.size() - 1 << endl;
  return 0;
}