#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<array<ll, 3>> plant;
const int IDX = 0;       // 按照高度，从高到低的排序,不能相等
const int ORIGINAL = 1;  // 原始高度
const int INCREMENT = 2; // 每天新增高度
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
    for (auto &pi : plant) {
      cin >> pi[ORIGINAL];
    }
    for (auto &pi : plant) {
      cin >> pi[INCREMENT];
    }
    for (auto &pi : plant) {
      cin >> pi[IDX];
    }
    // 按照要求的最终高度，从高到低排序，也就是IDX升序排序
    sort(plant.begin(), plant.end());
    bool isImpossible = false;
    ll mnDay = 0, mxDay = 1e9 + 10;
    for (ll i = 0; i < N - 1; i++) {
      array<ll, 3> curr = plant[i], next = plant[i + 1];
      if (curr[ORIGINAL] > next[ORIGINAL]) {
        mnDay = max(mnDay, 0LL);
        if (curr[INCREMENT] < next[INCREMENT]) {
          // curr需要大于 curr，差减 1，再整除确保了正好大于
          mxDay = min(mxDay, ((curr[ORIGINAL] - next[ORIGINAL]) - 1) /
                                 (next[INCREMENT] - curr[INCREMENT]));
        }
      } else if (curr[ORIGINAL] == next[ORIGINAL]) {
        // 需要大于
        if (curr[INCREMENT] > next[INCREMENT])
          mnDay = max(mnDay, 1LL);
        else {
          isImpossible = true;
          break;
        }
      } else { // curr小于 next
        if (curr[INCREMENT] <= next[INCREMENT]) {
          isImpossible = true;
          break;
        } else {
          // 整除加 1 确保了正好大于
          mnDay = max(mnDay, ((next[ORIGINAL] - curr[ORIGINAL]) /
                              (curr[INCREMENT] - next[INCREMENT])) +
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