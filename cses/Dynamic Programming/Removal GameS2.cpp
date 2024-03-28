#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<ll>> dp;
vector<ll> x;
vector<ll> preSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    preSum[i] = preSum[i - 1] + x[i];
  }
  dp.resize(2, vector<ll>(n + 1));
  int now = 0, old = 1;
  // 模拟选择的过程，看看状态是怎样转移的，两个选手的目标都是一样的，都是选取的值的和最大化
  // 两个选手所选数的总和等于序列中所有的数，考虑到同一个长度下，起点不同的各种可能，所有需要用前缀和来求总和
  // 所以当长度为 n 的时候，第一个选手只有两个选择，选头，则会转移到 2
  // 开头的长度为n-1的状态， 选尾则会转移到 1
  // 开头长度为n-1的状态，那我们正向递推 则可以从长度为
  // 1增加到n，每一个长度，把遍历所有可能的开头， 则可以保证从长度 i
  // 的阶段一定可以转移到长度为i-1 的阶段了，正向递推即可。
  for (int i = 1; i <= n; i++) { // i 表示序列的长度
    swap(now, old);
    // j 表示序列的起点
    for (int j = 1; j <= n - i + 1; j++) {
      // 第一个选项是选手选择开头的元素，则等于j+i-1的前缀和 减去
      // j的前缀和，等于i-1个元素的和，再减去 长度为 i-1,j+1为起点的最佳选择
      dp[now][j] = max(x[j] + preSum[j + i - 1] - preSum[j] - dp[old][j + 1],
                       x[j + i - 1] + preSum[j + i - 2] - preSum[j - 1] -
                           dp[old][j]); // 一头一尾
    }
  }
  cout << dp[now][1] << endl;
  return 0;
}