#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'

// Define constants for the array indices
const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;

vector<array<int, 3>> leftAsc, rightAsc;

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
  rightAsc.resize(leftAsc.size());
  copy(leftAsc.begin(), leftAsc.end(), rightAsc.begin());
  deque<array<int, 3>> dqDuplicate;

  // 解决isContained问题
  sort(leftAsc.begin(), leftAsc.end(), [](array<int, 3> i, array<int, 3> j) {
    return i[LEFT] == j[LEFT] ? i[RIGHT] > j[RIGHT] : i[LEFT] < j[LEFT];
  });
  int mxRight = 0;
  dqDuplicate.clear();
  for (int i = 0; i < n; i++) {
    if (!dqDuplicate.empty()) {
      if (dqDuplicate.front()[LEFT] == leftAsc[i][LEFT] &&
          dqDuplicate.front()[RIGHT] == leftAsc[i][RIGHT]) {
        isContained[dqDuplicate.front()[INDEX]] = 1;
        isContained[leftAsc[i][INDEX]] = 1;
        dqDuplicate.pop_front();
        continue;
      }
      dqDuplicate.pop_front();
    }
    if (leftAsc[i][RIGHT] <= mxRight) {
      isContained[leftAsc[i][INDEX]] = 1;
    } else {
      dqDuplicate.push_back(leftAsc[i]);
      mxRight = leftAsc[i][RIGHT];
    }
  }

  // 解决containsOther问题
  sort(rightAsc.begin(), rightAsc.end(), [](array<int, 3> i, array<int, 3> j) {
    return i[RIGHT] == j[RIGHT] ? i[LEFT] > j[LEFT] : i[RIGHT] < j[RIGHT];
  });
  int mnLeft = 0;
  dqDuplicate.clear();
  for (int i = 0; i < n; i++) {
    if (!dqDuplicate.empty()) {
      if (dqDuplicate.front()[LEFT] == rightAsc[i][LEFT] &&
          dqDuplicate.front()[RIGHT] == rightAsc[i][RIGHT]) {
        containsOther[dqDuplicate.front()[INDEX]] = 1;
        containsOther[rightAsc[i][INDEX]] = 1;
        dqDuplicate.pop_front();
        continue;
      }
      dqDuplicate.pop_front();
    }
    if (rightAsc[i][LEFT] <= mnLeft)
      containsOther[rightAsc[i][INDEX]] = 1;
    else {
      dqDuplicate.push_back(rightAsc[i]);
      mnLeft = rightAsc[i][LEFT];
    }
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}