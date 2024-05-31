#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll h, w, n;
vector<vector<array<ll, 2>>> duckR;
set<array<ll, 2>> stXY, stYX;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> h >> w >> n;
  duckR.resize(n);
  for (int i = 0; i < n; i++) {
    ll m;
    cin >> m;
    duckR[i].resize(m);
    for (auto &[yi, xi] : duckR[i]) {
      cin >> yi >> xi;
    }
  }

  for (auto di : duckR) {
    bool flagCollide = false;
    ll tx = 0, ty = 0;
    for (auto [yi, xi] : di) {
      ll sy = ty, sx = tx;
      ty += yi;
      tx += xi;
      auto itS = stXY.lower_bound({sx, sy});
      auto itT = stXY.lower_bound({sx, ty});
      if (itS != itT || (itS != stXY.end() && *itS == array<ll, 2>{sx, sy}) ||
          (itT != stXY.end() && *itT == array<ll, 2>{sx, ty})) {
        flagCollide = true;
      }
      itS = stYX.lower_bound({ty, sx});
      itT = stYX.lower_bound({ty, tx});
      if (itS != itT || (itS != stYX.end() && *itS == array<ll, 2>{ty, sx}) ||
          (itT != stYX.end() && *itT == array<ll, 2>{ty, tx})) {
        flagCollide = true;
      }
    }
    if (!flagCollide)
      cout << "smooth swimming" << endl;
    else
      cout << "OUCH" << endl;
    stYX.insert({ty, tx});
    stXY.insert({tx, ty});
  }
  return 0;
}