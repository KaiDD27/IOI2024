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
ll getDistance(array<ll, 2> a, array<ll, 2> b) {
  return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}
array<ll, 2> getFurthestPoint(ll col) {
  ll furthestDist = 0;
  array<ll, 2> furtestPoint;
  for (auto [ri, ci] : rc) {
    ll dist = getDistance({0, col}, {ri, ci});
    // 大于保证了furtestPoint是最左边的
    if (dist > furthestDist) {
      furthestDist = ri * ri + (ci - col) * (ci - col);
      furtestPoint = {ri, ci};
    }
  }
  return furtestPoint;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> r >> c >> n;
  rc.resize(n);
  for (auto &[ri, ci] : rc)
    cin >> ri >> ci;
  ll left = 0, right = c;
  // 左右相邻的情况无法直接判断哪个距离更短
  while (left < right - 1) {
    ll mid = left + (right - left) / 2;
    ll furthestCol = getFurthestPoint(mid)[1];
    if (furthestCol < mid)
      right = mid;
    else if (furthestCol > mid)
      left = mid;
    else
      left = right = mid;
  }
  if (getDistance({0, left}, getFurthestPoint(left)) <=
      getDistance({0, right}, getFurthestPoint(right))) {
    cout << left << endl;
  } else {
    cout << right << endl;
  }
  return 0;
}