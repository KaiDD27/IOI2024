#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;
vector<array<int, 3>> leftAsc;
vector<int> bitTree;
map<int, int> mpRightValToIndex;

void updateBIT(int i, int valChange) {
  while (i < bitTree.size()) {
    bitTree[i] += valChange;
    i += i & (-i);
  }
}

int queryBIT(int i) {
  int sum = 0;
  while (i > 0) {
    sum += bitTree[i];
    i -= i & (-i);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  leftAsc.resize(n);
  vector<int> isContained(n, 0), containsOther(n, 0);
  set<int> rightSet;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    leftAsc[i][LEFT] = l;
    leftAsc[i][RIGHT] = r;
    leftAsc[i][INDEX] = i;
    rightSet.insert(r); // 获得 RIGHT 值形成的BIT的数组的个数
  }
  bitTree.resize(rightSet.size() + 1); // 所以从 1 开始所以，size 加 1
  // 构造一个 Map 方便从 Right 的值查询对应到 BIT 数组的位置，注意 BIT 的索引从
  // 1 开始
  {
    int iTree = 1;
    for (auto val : rightSet) {
      mpRightValToIndex[val] = iTree;
      iTree++;
    }
  }
  /*这段代码实现了和上面代码类似的功能，但是由于set底层是链表容器，next这个函数时间复杂度是n，所以整体就会变成
  O（n^2)
  for (int iTree = 1; iTree <= rightSet.size(); iTree++) { auto val =
  *next(rightSet.begin(), iTree - 1); mpRightValToIndex[val] = iTree;
  }
 */

  // 按照 Left 升序排序，Left相等，则Right 降序排序
  sort(leftAsc.begin(), leftAsc.end(), [&](auto a, auto b) {
    return a[LEFT] == b[LEFT] ? a[RIGHT] > b[RIGHT] : a[LEFT] < b[LEFT];
  });
  // 降序遍历 Left（Left 相等，则是升序遍历
  // Right），这样可以确保找到所有的包含关系
  for (int i = n - 1; i >= 0; i--) {
    int iTree = mpRightValToIndex[leftAsc[i][RIGHT]];
    containsOther[leftAsc[i][INDEX]] = queryBIT(iTree);
    updateBIT(iTree, 1);
  }

  // 升序遍历 Left（Left 相等，则是降序遍历
  // Right），这样可以确保找到所有的被包含关系
  fill(bitTree.begin(), bitTree.end(), 0);
  for (int i = 0; i < leftAsc.size(); i++) {
    int iTree = mpRightValToIndex[leftAsc[i][RIGHT]];
    isContained[leftAsc[i][INDEX]] =
        queryBIT(bitTree.size() - 1) - queryBIT(iTree - 1);
    updateBIT(iTree, 1);
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";

  return 0;
}