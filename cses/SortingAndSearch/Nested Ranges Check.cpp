#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
// Define constants for the array indices
const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;
vector<array<int, 3>> leftAsc;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  leftAsc.resize(n);
  vector<int> isContained(n, 0), containsOther(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> leftAsc[i][LEFT] >> leftAsc[i][RIGHT];
    leftAsc[i][INDEX] = i;
  }
  sort(leftAsc.begin(), leftAsc.end(), [](array<int, 3> i, array<int, 3> j) {
    return i[LEFT] == j[LEFT] ? i[RIGHT] > j[RIGHT] : i[LEFT] < j[LEFT];
  });

  // 解决isContained问题
  for (int i = 0, mxRight = 0; i < n; i++) {
    if (leftAsc[i][RIGHT] <= mxRight) {
      isContained[leftAsc[i][INDEX]] = 1;
    } else {
      mxRight = max(mxRight, leftAsc[i][RIGHT]);
    }
  }

  // 解决containsOther问题
  for (int i = n - 1, mnRight = 1e9 + 10; i >= 0; i--) {
    if (leftAsc[i][RIGHT] >= mnRight) {
      containsOther[leftAsc[i][INDEX]] = 1;
    } else {
      mnRight = min(mnRight, leftAsc[i][RIGHT]);
    }
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}