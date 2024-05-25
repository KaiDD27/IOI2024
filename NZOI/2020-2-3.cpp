#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, t;
map<ll, ll> mpX;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> t;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    ll xi;
    cin >> xi;
    mpX[xi]++;
  }

  while (t > 0) {
    auto [smallest, smallestCnt] = *mpX.begin();
    auto [bigest, bigestCnt] = *mpX.rbegin();
    if (bigest - smallest <= 1) {
      break;
    }
    // 这个剪枝没有必要
    if (t < min(mpX.begin()->second, mpX.rbegin()->second))
      break;

    if (mpX.size() == 2) {
      ll ret = (smallest * smallestCnt + bigest * bigestCnt) /
               (smallestCnt + bigestCnt);
      if (t >=
          max((ret - smallest) * smallestCnt, (bigest - ret - 1) * bigestCnt)) {
        if ((smallest * smallestCnt + bigest * bigestCnt) %
                (smallestCnt + bigestCnt) ==
            0)
          cout << 0 << endl;
        else
          cout << 1 << endl;
      } else {
        cout << bigest - t / bigestCnt - (smallest + t / smallestCnt) << endl;
      }
      return 0;
    }
    auto secondSmallest = next(mpX.begin())->first;
    // 倒序下一个，就是倒数第二大的
    auto secondBigest = next(mpX.rbegin())->first;
    ll needT = min((secondSmallest - smallest) * smallestCnt,
                   (bigest - secondBigest) * bigestCnt);
    ll usedT;
    if (t >= needT) {
      t -= needT;
      usedT = needT;
    } else {
      t = 0;
      usedT = t;
    }
    mpX.erase(smallest);
    mpX.erase(bigest);
    mpX[smallest + usedT / smallestCnt] += (smallestCnt - usedT % smallestCnt);
    if (usedT % smallestCnt != 0)
      mpX[smallest + usedT / smallestCnt + 1] += usedT % smallestCnt;
    mpX[bigest - usedT / bigestCnt] += (bigestCnt - usedT % bigestCnt);
    if (usedT % bigestCnt != 0)
      mpX[bigest - usedT / bigestCnt - 1] += usedT % bigestCnt;
  }
  ll ans = mpX.rbegin()->first - mpX.begin()->first;
  cout << ans << endl;
  return 0;
}