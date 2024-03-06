#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
namespace gp = __gnu_pbds;
typedef gp::tree<int, gp::null_type, less<int>, gp::rb_tree_tag,
                 gp::tree_order_statistics_node_update>
    ordered_set;
ordered_set os;
using ll = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    os.insert(i);
  for (auto it = os.begin(); !os.empty();) {
    it = os.find_by_order((os.order_of_key(*it) + k) % os.size());
    auto itDel = it;
    it++;
    if (it == os.end())
      it = os.begin();
    cout << *itDel << " ";
    os.erase(itDel);
  }
  return 0;
}