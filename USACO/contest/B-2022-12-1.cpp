#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
vector<ll> c;
map<ll, ll> mpMxTuituionToCnt;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  c.resize(n);
  for (auto &ci : c) {
    cin >> ci;
    mpMxTuituionToCnt[ci]++;
  }
  ll preSum = 0;
  for (auto it = mpMxTuituionToCnt.rbegin(); it != mpMxTuituionToCnt.rend();
       it++) {
    it->second = it->second + preSum;
    preSum = it->second;
  }
  ll mxMoney = 0, smallestTution = LLONG_MAX;
  for (auto mi : mpMxTuituionToCnt) {
    ll money = mi.first * mi.second;
    if (money > mxMoney) {
      mxMoney = money;
      smallestTution = mi.first;
    }
  }
  cout << mxMoney << " " << smallestTution << endl;
  return 0;
}