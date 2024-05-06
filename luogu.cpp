#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a;
// 请注意要传nums引用，不然容易爆内存
int findNthElement(vector<int> &nums, int left, int right, int nTh) {
  if (left >= right)
    return nums[left];
  int lessThan = left, i = left, greaterThan = right;
  int flag = nums[left + rand() % (right - left + 1)];
  while (i <= greaterThan) {
    if (nums[i] < flag)
      swap(nums[i++], nums[lessThan++]);
    else if (nums[i] > flag)
      swap(nums[i], nums[greaterThan--]);
    else
      i++;
  }
  if (nTh <= lessThan - 1)
    return findNthElement(nums, left, lessThan - 1, nTh);
  else if (nTh >= greaterThan + 1)
    return findNthElement(nums, greaterThan + 1, right, nTh);
  else
    return flag;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  a.resize(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  int ans = findNthElement(a, 0, a.size() - 1, k);
  cout << ans << endl;

  return 0;
}