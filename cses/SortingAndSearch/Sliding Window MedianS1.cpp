#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'

set<pair<int, int>> mSet;
vector<int> x;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  x.resize(n);
  for (auto &xi : x)
    cin >> xi;
  if (k == 1) {
    for_each(x.begin(), x.end(), [](int i) { cout << i << " "; });
    return 0;
  }
  for (int i = 0; i < k; i++)
    mSet.insert({x[i], i});
  auto it = mSet.begin();
  advance(it, (k - 1) / 2); // 等同于for循环 it++ (k-1)/2次
  cout << it->first << " ";
  for (int l = 0, r = k; r < n; r++, l++) {
    // 删掉的正好是中位数的元素
    if (x[l] == it->first && l == it->second) {
      it++; // 往右移了才能删除
      mSet.erase({x[l], l});
      mSet.insert({x[r], r});
      if (x[r] < it->first) { // 小于的话则往左移回去
        it--;
      } // 大于等于的话，因为 Index 越来越大，所以则必定会在右侧，所以不用移动it
    } else {
      mSet.erase({x[l], l});
      mSet.insert({x[r], r});
      if (x[l] <= it->first && x[r] >= it->first)
        it++;
      else if (x[l] > it->first && x[r] < it->first) {
        it--;
      }
      // x[l]和x[r]在同一边则中位数不变
    }
    cout << it->first << " ";
  }
  return 0;
}
