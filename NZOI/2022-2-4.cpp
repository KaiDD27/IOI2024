#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll r, c, n;
ll cLeft, cRight;
vector<array<ll, 2>> rc;

bool isStrainEnough(ll strainSquare) {
  cLeft = 0, cRight = c - 1;
  for (auto [ri, ci] : rc) {
    if (strainSquare - ri * ri < 0)
      return false;
    // 不要用sqrt，因为精度可能不够，一定要用sqrtl！！！
    ll gap = sqrtl(strainSquare - ri * ri);
    cLeft = max(cLeft, ci - gap);
    cRight = min(cRight, ci + gap);
    if (cLeft > cRight)
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> r >> c >> n;
  rc.resize(n);
  for (auto &[ri, ci] : rc)
    cin >> ri >> ci;
  ll left = 1, right = (c / 2 + 1) * (c / 2 + 1) + r * r;
  while (left < right) {
    ll mid = left + (right - left) / 2;
    if (isStrainEnough(mid))
      right = mid;
    else
      left = mid + 1;
  }
  isStrainEnough(left);
  cout << cLeft << endl;
  return 0;
}