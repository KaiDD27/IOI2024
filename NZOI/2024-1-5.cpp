#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n, m;
vector<ll> t;
vector<vector<ll>> adj, dp;
// dfsNextButNotSubTree是dfs
// 先序遍历里面排在当前节点之后,且不是当前节点的子节点的第一个节点，其实就是先序遍历排在当前节点后面的第一个兄弟节点
void dfs(int a, int dfsNextButNotSubTree, int father) {
  // curr_Next可以作为先序遍历当前节点的下一个节点，且curr_Next节点的 dp
  // 都已经算好了，可以确保状态转移成功。当这个节点不是子节点的时候，等于dfsNextButNotSubTree
  int curr_Next = dfsNextButNotSubTree;
  for (auto b : adj[a]) {
    if (b == father)
      continue;
    dfs(b, curr_Next, a);
    curr_Next = b;
  }
  // 就是按照先序遍历从末尾一步步递推上来的
  for (int k = 0; k <= m; k++) {
    dp[a][k] = min(dp[dfsNextButNotSubTree][k],
                   t[a] + (k > t[a] ? dp[curr_Next][k - t[a]] : 0));
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  t.resize(n);
  adj.resize(n);
  dp.resize(n + 1, vector<ll>(m + 1, 5000));
  // 这行代码初始化了dp数组
  // dp是一个二维vector，大小为(n+1) x (m+1)
  // n+1是因为我们需要包含从0到n的所有节点
  // m+1是因为我们需要考虑从0到m的所有可能的时间
  // 所有元素初始化为5000，这是一个足够大的值，用作初始的最大值
  // 在后续的动态规划过程中，我们会更新这些值为实际的最小甜度
  for (auto &ti : t)
    cin >> ti;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // dfs 先序遍历最后一个节点的下一个节点就是 n，n 是虚拟出来的节点，相当于墙
  dfs(0, n, -1);
  cout << dp[0][m] << endl;
  return 0;
}