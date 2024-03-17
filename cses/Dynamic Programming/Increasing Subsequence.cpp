#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  int x;
  cin >> x;
  dp.push_back(x);
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x > *dp.rbegin())
      dp.push_back(x);
    else {
      auto it = lower_bound(dp.begin(), dp.end(), x);
      *it = x;
    }
  }
  cout << dp.size() << endl;
  return 0;
}
/*这个问题的动态规划思想主要体现在构建和更新 dp 数组的过程中。dp 数组的每个元素
dp[i] 代表的是长度为 i+1
的所有递增子序列中，末尾元素最小的那个。这个数组是在遍历输入数组的过程中逐步构建的，每一步都利用了前一步的结果。

具体来说，当我们遍历输入数组，对于每一个元素，我们都尝试将它添加到 dp
数组中。如果它大于 dp 中的所有元素，那么我们可以将它添加到 dp
的末尾，这意味着我们找到了一个更长的递增子序列。否则，我们使用二分查找找到 dp
中第一个大于等于当前元素的位置，将该位置的元素更新为当前元素。这是因为对于长度为
i+1
的递增子序列，我们总是希望其末尾元素尽可能小，这样在后面就更有可能添加更多的元素。

这个过程就是动态规划的过程，我们在每一步都利用了前一步的结果（也就是 dp
数组的当前状态）来更新 dp
数组，从而得到更长的递增子序列。这就是动态规划的思想，即将大问题分解为小问题，并利用小问题的解决方案来解决大问题。

最后，dp 数组的长度就是最长递增子序列的长度，因为 dp
数组的每个元素都代表了一个递增子序列的末尾元素，而且这些递增子序列的长度是递增的。所以，dp
数组的长度就是最长递增子序列的长度。*/