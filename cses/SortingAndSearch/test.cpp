#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
#define endl '\n'
array<array<int, 3>, 200000 + 10> leftAsc, rightAsc;
map<int, int> mp;
const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  vector<int> isContained(n, 0), containsOther(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> leftAsc[i][LEFT] >> leftAsc[i][RIGHT];
    leftAsc[i][INDEX] = i;
  }
  copy(leftAsc.begin(), leftAsc.begin() + n, rightAsc.begin());

  sort(leftAsc.begin(), leftAsc.begin() + n,
       [&](array<int, 3> a, array<int, 3> b) {
         return a[LEFT] == b[LEFT] ? a[RIGHT] > b[RIGHT] : a[LEFT] < b[LEFT];
       });

  deque<array<int, 3>> dqDuplicate;
  for (int i = 0; i < n; i++) {
    array<int, 3> curr = leftAsc[i];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == curr[LEFT] &&
        dqDuplicate.front()[RIGHT] == curr[RIGHT]) {
      dqDuplicate.push_back(curr);
    } else {
      while (!dqDuplicate.empty()) {
        isContained[dqDuplicate.front()[INDEX]] += (dqDuplicate.size() - 1);
        dqDuplicate.pop_front();
      }
      dqDuplicate.push_back(curr);
    }
    auto it = mp.lower_bound(curr[RIGHT]);
    int sum = 0;
    for (; it != mp.end(); ++it) {
      sum += it->second;
    }
    isContained[curr[INDEX]] = sum;
    mp[curr[RIGHT]]++;
  }
  while (!dqDuplicate.empty()) {
    isContained[dqDuplicate.front()[INDEX]] += (dqDuplicate.size() - 1);
    dqDuplicate.pop_front();
  }

  sort(rightAsc.begin(), rightAsc.begin() + n,
       [&](array<int, 3> a, array<int, 3> b) {
         return a[RIGHT] == b[RIGHT] ? a[LEFT] > b[LEFT] : a[RIGHT] < b[RIGHT];
       });
  mp.clear();
  dqDuplicate.clear();
  for (int i = 0; i < n; i++) {
    array<int, 3> curr = rightAsc[i];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == curr[LEFT] &&
        dqDuplicate.front()[RIGHT] == curr[RIGHT]) {
      dqDuplicate.push_back(curr);
    } else {
      while (!dqDuplicate.empty()) {
        containsOther[dqDuplicate.front()[INDEX]] += (dqDuplicate.size() - 1);
        dqDuplicate.pop_front();
      }
      dqDuplicate.push_back(curr);
    }

    auto it = mp.lower_bound(curr[LEFT]);
    int sum = 0;
    for (; it != mp.end(); ++it) {
      sum += it->second;
    }
    containsOther[curr[INDEX]] = sum;
    mp[curr[LEFT]]++;
  }
  while (!dqDuplicate.empty()) {
    containsOther[dqDuplicate.front()[INDEX]] += (dqDuplicate.size() - 1);
    dqDuplicate.pop_front();
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";

  return 0;
}