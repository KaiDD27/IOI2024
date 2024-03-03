#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;

namespace gp = __gnu_pbds;

typedef gp::tree<int, gp::null_type, less<int>, gp::rb_tree_tag,
                 gp::tree_order_statistics_node_update>
    ordered_set;

int main() {
  ordered_set s;
  s.insert(1);
  s.insert(3);
  s.insert(4);
  s.insert(2);

  // 输出集合中的元素
  for (int i = 0; i < s.size(); i++) {
    cout << *s.find_by_order(i) << " ";
  }
  cout << endl;

  // 输出元素3在集合中的位置（0-based）
  cout << s.order_of_key(3) << endl;

  return 0;
}