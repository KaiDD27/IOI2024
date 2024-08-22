#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, t;
  cin >> n >> t;

  if (n == 1) {
    cout << "0\n";
    return 0;
  }

  map<ll, ll> mpX;
  for (int i = 0; i < n; i++) {
    ll xi;
    cin >> xi;
    mpX[xi]++;
  }

  while (t > 0) {
    auto [smallest, smallestCnt] = *mpX.begin();
    auto [largest, largestCnt] = *mpX.rbegin();

    if (largest - smallest <= 1)
      break;

    if (mpX.size() == 2) {
      ll total = smallest * smallestCnt + largest * largestCnt;
      ll count = smallestCnt + largestCnt;
      ll avg = total / count;
      ll moves =
          max((avg - smallest) * smallestCnt, (largest - avg) * largestCnt);

      if (t >= moves) {
        cout << (total % count == 0 ? "0\n" : "1\n");
      } else {
        cout << largest - t / largestCnt - (smallest + t / smallestCnt) << "\n";
      }
      return 0;
    }

    ll secondSmallest = next(mpX.begin())->first;
    ll secondLargest = prev(mpX.rbegin())->first;
    ll needT = min((secondSmallest - smallest) * smallestCnt,
                   (largest - secondLargest) * largestCnt);
    ll usedT = min(t, needT);

    t -= usedT;

    // Update the map
    mpX.erase(smallest);
    mpX.erase(largest);
    mpX[smallest + usedT / smallestCnt] += smallestCnt - usedT % smallestCnt;
    if (usedT % smallestCnt != 0)
      mpX[smallest + usedT / smallestCnt + 1] += usedT % smallestCnt;
    mpX[largest - usedT / largestCnt] += largestCnt - usedT % largestCnt;
    if (usedT % largestCnt != 0)
      mpX[largest - usedT / largestCnt - 1] += usedT % largestCnt;
  }

  cout << mpX.rbegin()->first - mpX.begin()->first << "\n";
  return 0;
}