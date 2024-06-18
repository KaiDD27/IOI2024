#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll N;
  cin >> N;
  a.resize(N);
  for (auto &ai : a)
    cin >> ai;
  ll sprayerAddCnt = 0, sprayerRemoveCnt = 0;
  for (ll i = 0, totalAddNumOfCurrPos = 0, totalRemoveNumOfCurrPos = 0; i < N;
       i++) {
    a[i] += totalAddNumOfCurrPos;
    a[i] -= totalRemoveNumOfCurrPos;
    if (a[i] > 0) {
      sprayerRemoveCnt += a[i];
      totalRemoveNumOfCurrPos += a[i];
    } else if (a[i] < 0) {
      sprayerAddCnt += abs(a[i]);
      totalAddNumOfCurrPos += abs(a[i]);
    }
    totalRemoveNumOfCurrPos += sprayerRemoveCnt;
    totalAddNumOfCurrPos += sprayerAddCnt;
  }
  cout << sprayerAddCnt + sprayerRemoveCnt << endl;
  return 0;
}