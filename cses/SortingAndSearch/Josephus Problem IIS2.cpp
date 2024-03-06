/*这段代码是用来解决约瑟夫问题 II
的，它使用了一种数据结构叫做二进制索引树（Binary Indexed Tree，BIT）。

以下是对每个函数的详细解释：

update(ll idx, ll
val)：这个函数用于更新二进制索引树。它将val加到索引idx及其所有父节点上。

get_sum(ll idx)：这个函数用于获取二进制索引树中前idx个元素的和。

get_kth(ll
k)：这个函数用于获取二进制索引树中第k个元素的索引。它使用了二分查找的方法，从高位到低位逐位检查，如果当前位加上2的i次方的位置的元素数量小于k，那么就将当前位加上2的i次方，并从k中减去那个位置的元素数量。

在main函数中：

ios::sync_with_stdio(false);
cin.tie(nullptr);：这两行代码用于加快C++的输入输出速度。

bit.resize(n + 1);：这行代码将二进制索引树的大小设置为n + 1。

接下来的for循环将二进制索引树的每个元素初始化为1，表示每个孩子都在游戏中。

最后的for循环模拟了游戏的过程。在每次迭代中，它计算出要被移除的孩子的新位置idx，使用get_kth函数找到那个位置的孩子，打印出那个位置，然后更新二进制索引树以从游戏中移除那个孩子。

return 0;表示程序成功结束。*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> bit;

void update(ll idx, ll val) {
  while (idx < bit.size()) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}

ll sum(ll idx) {
  ll sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}

ll get_kth(ll k) {
  ll idx = 0;
  for (ll i = 20; i >= 0; --i) {
    if (idx + (1 << i) < bit.size() && bit[idx + (1 << i)] < k) {
      idx += 1 << i;
      k -= bit[idx];
      cout << endl << "k=" << k << endl;
    }
  }
  return idx + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  bit.resize(n + 1);
  for (ll i = 1; i <= n; ++i) {
    update(i, 1);
  }

  ll idx = 0;
  for (ll i = 0; i < n; ++i) {
    idx = (idx + k) % sum(n);
    ll pos = get_kth(idx + 1);
    cout << pos << ' ';
    update(pos, -1);
  }

  return 0;
}