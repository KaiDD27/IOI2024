#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, ll>> plant;
vector<int> plantIdSorted; // 按照最重要的的高度，对plant从高到低排序

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll N;
    cin >> N;
    plant.clear();
    plant.resize(N);
    plantIdSorted.clear();
    plantIdSorted.resize(N);
    for (auto &pi : plant) {
      cin >> pi.first;
    }
    for (auto &pi : plant) {
      cin >> pi.second;
    }
    for (int i = 0; i < N; i++) {
      int sortedPos;
      cin >> sortedPos;
      plantIdSorted[sortedPos] = i;
    }

    bool isImpossible = false;
    ll mnDay = 0, mxDay = 1e9 + 10;
    for (int psi = 0; psi < N - 1; psi++) {

      ll currOriginal = plant[plantIdSorted[psi]].first,
         currIncrement = plant[plantIdSorted[psi]].second;
      ll nextOriginal = plant[plantIdSorted[psi + 1]].first,
         nextIncrement = plant[plantIdSorted[psi + 1]].second;
      if (currOriginal > nextOriginal) {
        mnDay = max(mnDay, 0LL);
        if (currIncrement < nextIncrement) {
          mxDay = min(mxDay, ((currOriginal - nextOriginal) - 1) /
                                 (nextIncrement - currIncrement));
        }
      } else if (currOriginal == nextOriginal) {
        if (currIncrement > nextIncrement)
          mnDay = max(mnDay, 1LL);
        else {
          isImpossible = true;
          break;
        }
      } else {
        if (currIncrement <= nextIncrement) {
          isImpossible = true;
          break;
        } else {
          mnDay = max(mnDay, ((nextOriginal - currOriginal) /
                              (currIncrement - nextIncrement)) +
                                 1);
        }
      }
      if (mnDay > mxDay) {
        isImpossible = true;
        break;
      }
    }
    if (isImpossible == true)
      cout << "-1" << endl;
    else
      cout << mnDay << endl;
  }
  return 0;
}