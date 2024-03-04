#include <algorithm>
#include <cstdlib>
#include <iostream>
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
  for (auto &i : x)
    cin >> i;
  if (k == 1) {
    for_each(x.begin(), x.end(), [](int i) { cout << 0 << " "; });
    return 0;
  }

  for (int i = 0; i < k; i++)
    mSet.emplace(make_pair(x[i], i));
  auto it = mSet.begin();
  for (int i = 0; i < (k - 1) / 2; i++) {
    it++;
  }
  ll cost = 0;
  for (auto m : mSet)
    cost += abs(m.first - it->first);
  cout << cost << " ";
  for (int l = 0, r = k; r < n; r++, l++) {
    int prevMedianVal = it->first;
    // 删掉的正好是中位数的元素
    if (x[l] == it->first && l == it->second) {
      it++; // 往右移了才能删除
      mSet.erase({x[l], l});
      mSet.emplace(make_pair(x[r], r));
      if (x[r] < it->first) { // 小于的话则往左移回去
        it--;
      } // 大于等于的话，因为 Index 越来越大，所以则必定会在右侧，所以不用移动it
    } else if (x[l] <= it->first) { // 由于 index 递增，所以必然是在左侧
      mSet.erase({x[l], l});
      mSet.emplace(make_pair(x[r], r));
      if (x[r] >= it->first) {
        it++;
      }
    } else {
      mSet.erase({x[l], l});
      mSet.emplace(make_pair(x[r], r));
      if (x[r] < it->first) {
        it--;
      }
    }

    cost -= abs(x[l] - prevMedianVal);
    cost += abs(x[r] - it->first);
    ll difference = it->first - prevMedianVal;
    // 中位数的值没有变的情况下，不需要处理，变化的情况下，需要分类处理，共 4
    // 类如下：
    if (difference > 0) {
      if (k % 2 == 1) {
        cost += (k / 2) * difference;
      } else {
        cost += (k / 2 - 1) * difference;
      }
      cost -= (k / 2) * difference;
    }
    if (difference < 0) {
      cost += (k / 2) * difference * (-1);
      if (k % 2 == 1) {
        cost -= (k / 2) * difference * (-1);
      } else {
        cost -= (k / 2 - 1) * difference * (-1);
      }
    }
    cout << cost << " ";
  }
  return 0;
}
