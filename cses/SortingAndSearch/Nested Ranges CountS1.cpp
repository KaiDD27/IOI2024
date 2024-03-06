#include <algorithm>
#include <array>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
namespace gp = __gnu_pbds;
typedef gp::tree<std::pair<int, int>, gp::null_type, less<std::pair<int, int>>,
                 gp::rb_tree_tag, gp::tree_order_statistics_node_update>
    ordered_set;
ordered_set os;
using ll = long long;
#define endl '\n'
vector<array<int, 3>> leftAsc;
deque<array<int, 3>> dqDuplicate;
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
  for (int i = 0; i < n; i++) {
    int left = leftAsc[i][LEFT], right = leftAsc[i][RIGHT],
        index = leftAsc[i][INDEX];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == left &&
        dqDuplicate.front()[RIGHT] == right) {
      for (auto dup : dqDuplicate) {
        isContained[dup[INDEX]]++;
      }
    } else {
      dqDuplicate.clear();
    }
    dqDuplicate.push_back({left, right, index});
    isContained[index] += (os.size() - os.order_of_key({right, -1}));
    os.insert({right, index});
  }

  os.clear();
  dqDuplicate.clear();
  for (int i = n - 1; i >= 0; i--) {
    int left = leftAsc[i][LEFT], right = leftAsc[i][RIGHT],
        index = leftAsc[i][INDEX];
    if (!dqDuplicate.empty() && dqDuplicate.front()[LEFT] == left &&
        dqDuplicate.front()[RIGHT] == right) {
      for (auto dup : dqDuplicate) {
        containsOther[dup[INDEX]]++;
      }
    } else {
      dqDuplicate.clear();
    }
    dqDuplicate.push_back({left, right, index});
    containsOther[index] += os.order_of_key({right, n + 1});
    os.insert({right, index});
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}