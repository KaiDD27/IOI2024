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
  vector<int> isContained(n, 0), containsOther(n, 0);
  for (int i = 0; i < n; i++) {
    int left, right;
    cin >> left >> right;
    leftAsc.push_back({left, right, i});
  }
  sort(leftAsc.begin(), leftAsc.end(), [](array<int, 3> i, array<int, 3> j) {
    return i[LEFT] == j[LEFT] ? i[RIGHT] > j[RIGHT] : i[LEFT] < j[LEFT];
  });

  int prevLeft = -1, prevRight = -1, prevId = -1;
  // 解决isContained问题
  int mxRight = 0;
  for (int i = 0; i < n; i++) {
    array<int, 3> curr = leftAsc[i];
    if (prevLeft == curr[LEFT] && prevRight == curr[RIGHT])
      isContained[prevId] = 1;
    else {
      prevLeft = curr[LEFT];
      prevRight = curr[RIGHT];
      prevId = curr[INDEX];
    }
    if (curr[RIGHT] <= mxRight) {
      isContained[curr[INDEX]] = 1;
    } else {
      mxRight = curr[RIGHT];
    }
  }

  // 解决containsOther问题
  prevLeft = -1, prevRight = -1, prevId = -1;
  int mnRight = 1e9 + 10;
  for (int i = n - 1; i >= 0; i--) {
    array<int, 3> curr = leftAsc[i];
    if (prevLeft == curr[LEFT] && prevRight == curr[RIGHT])
      isContained[prevId] = 1;
    else {
      prevLeft = curr[LEFT];
      prevRight = curr[RIGHT];
      prevId = curr[INDEX];
    }
    if (curr[RIGHT] >= mnRight) {
      containsOther[curr[INDEX]] = 1;
    } else {
      mnRight = curr[RIGHT];
    }
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}