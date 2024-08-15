#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const int MOD = 1e9 + 7;
vector<ll> h;
vector<array<ll, 3>> t;
map<ll, array<ll, 2>> mpH;
vector<array<ll, 4>> hCntT;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, q;
  cin >> n >> q;
  h.resize(n);
  for (auto &hi : h) {
    cin >> hi;
    mpH[hi][0]++;
  }
  // 首尾各有一堵墙
  hCntT.resize(mpH.size() + 2);
  ll tmpHi = 1;
  for (auto mi : mpH) {
    hCntT[tmpHi][0] = mi.first;
    hCntT[tmpHi][1] = mi.second[0];
    hCntT[tmpHi][2] = mi.second[1];
    tmpHi++;
  }
  t.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i][0];
    t[i][1] = i;
  }
  ll tmpColumn = 0;
  ll tmpHSum = 0;
  ll tmpTSum = 0;
  for (int i = mpH.size(); i > 0; i--) {
    hCntT[i][1] += tmpColumn;
    tmpColumn = hCntT[i][1];
    hCntT[i][2] = (hCntT[i][0] - hCntT[i - 1][0]) * hCntT[i][1];
    hCntT[i][2] += tmpHSum;
    tmpHSum = hCntT[i][2];
    hCntT[i][3] = (hCntT[i][0] - hCntT[i - 1][0]) *
                  (hCntT[i - 1][0] + 1 + hCntT[i][0]) / 2;
    // 上面一行最大情况可能会long long 越界，所以必须立即 MOD，然后在乘下一个数
    hCntT[i][3] %= MOD;
    hCntT[i][3] *= hCntT[i][1];
    hCntT[i][3] %= MOD;
    hCntT[i][3] += tmpTSum;
    hCntT[i][3] %= MOD;
    tmpTSum = hCntT[i][3];
  }

  sort(t.begin(), t.end());
  for (int qi = 0, hi = mpH.size(); qi < q; qi++) {
    ll ti = t[qi][0];
    while (ti > hCntT[hi][2]) {
      hi--;
      if (hi == 0)
        break;
    }
    if (hi == 0) {
      hi = 1;
      t[qi][2] = hCntT[hi][3];
      continue;
    }
    ll line = (ti - hCntT[hi + 1][2]) / hCntT[hi][1];
    ll column = (ti - hCntT[hi + 1][2]) % hCntT[hi][1];
    t[qi][2] = hCntT[hi + 1][3];
    ll tmp = line * (hCntT[hi][0] + hCntT[hi][0] - line + 1) / 2;
    // 上面一行最大情况可能会long long 越界，所以必须立即 MOD，然后在乘下一个数
    tmp %= MOD;
    tmp *= hCntT[hi][1];
    tmp %= MOD;
    t[qi][2] += tmp;
    t[qi][2] %= MOD;
    t[qi][2] += column * (hCntT[hi][0] - line);
    t[qi][2] %= MOD;
  }
  sort(t.begin(), t.end(),
       [&](array<ll, 3> a, array<ll, 3> b) { return a[1] < b[1]; });
  for (auto ti : t)
    cout << ti[2] << endl;

  return 0;
}