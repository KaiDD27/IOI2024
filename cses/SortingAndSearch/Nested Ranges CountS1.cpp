#include <algorithm>
#include <array>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
using namespace std;
namespace gp = __gnu_pbds;
// 不支持重复元素，所以需要用pair,通过 second,index来区分
typedef gp::tree<std::pair<int, int>, gp::null_type, less<std::pair<int, int>>,
                 gp::rb_tree_tag, gp::tree_order_statistics_node_update>
    ordered_set;
ordered_set os;
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

  for (int i = n - 1; i >= 0; i--) {
    int right = leftAsc[i][RIGHT], index = leftAsc[i][INDEX];
    // 返回的是严格小于key的数量，也就是0-base 下key的序号
    containsOther[index] = os.order_of_key({right, n + 1});
    os.insert({right, index});
  }

  os.clear();

  for (int i = 0; i < n; i++) {
    int right = leftAsc[i][RIGHT], index = leftAsc[i][INDEX];
    isContained[index] = (os.size() - os.order_of_key({right, -1}));
    os.insert({right, index});
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}