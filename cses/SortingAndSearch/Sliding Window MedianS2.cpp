#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
namespace gp = __gnu_pbds;
typedef gp::tree<std::pair<int, int>, gp::null_type, less<std::pair<int, int>>,
                 gp::rb_tree_tag, gp::tree_order_statistics_node_update>
    ordered_set;
ordered_set os;
vector<int> x;
int main() {
  int n, k;
  cin >> n >> k;
  x.resize(n);
  for (auto &xi : x) {
    cin >> xi;
  }
  for (int i = 0; i < k; i++) {
    os.insert({x[i], i});
  }
  cout << (*os.find_by_order((k - 1) / 2)).first << " ";
  for (int l = 0, r = k; r < n; l++, r++) {
    os.erase({x[l], l});
    os.insert({x[r], r});
    cout << (*os.find_by_order((k - 1) / 2)).first << " ";
  }
  return 0;
}