#include <algorithm>
#include <array>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <utility>
using namespace std;
namespace gp = __gnu_pbds;

typedef gp::tree<std::pair<int, int>, gp::null_type, less<std::pair<int, int>>,
                 gp::rb_tree_tag, gp::tree_order_statistics_node_update>
    ordered_set;
using ll = long long;
#define endl '\n'
vector<array<int, 3>> leftAsc;

const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;
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

  sort(leftAsc.begin(), leftAsc.begin() + n,
       [&](array<int, 3> a, array<int, 3> b) {
         return a[LEFT] == b[LEFT] ? a[RIGHT] > b[RIGHT] : a[LEFT] < b[LEFT];
       });

  deque<array<int, 3>> dqDuplicate;
  ordered_set os;
  for (int i = 0; i < n; i++) {
    array<int, 3> curr = leftAsc[i];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == curr[LEFT] &&
        dqDuplicate.front()[RIGHT] == curr[RIGHT]) {
      for (auto dup : dqDuplicate) {
        isContained[dup[INDEX]]++;
      }
    } else {
      dqDuplicate.clear();
    }
    dqDuplicate.emplace_back(curr);
    isContained[curr[INDEX]] +=
        (os.size() - os.order_of_key(make_pair(curr[RIGHT], -1)));
    os.insert(make_pair(curr[RIGHT], curr[INDEX]));
  }

  os.clear();
  dqDuplicate.clear();
  for (int i = n - 1; i >= 0; i--) {
    array<int, 3> curr = leftAsc[i];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == curr[LEFT] &&
        dqDuplicate.front()[RIGHT] == curr[RIGHT]) {
      for (auto dup : dqDuplicate) {
        containsOther[dup[INDEX]]++;
      }
    } else {
      dqDuplicate.clear();
    }
    dqDuplicate.emplace_back(curr);
    containsOther[curr[INDEX]] +=
        (os.order_of_key(make_pair(curr[RIGHT], n + 1)));
    os.insert(make_pair(curr[RIGHT], curr[INDEX]));
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}