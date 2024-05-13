// 洛谷P2015的代码（邻接表存树）
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200;
struct node {
  int v, w; // v是子结点，w是边[u,v]的值
  node(int v = 0, int w = 0) : v(v), w(w) {}
};
vector<node> edge[N];
int dp[N][N], sum[N]; // sum[i]记录以点i为根的子树的总边数
int n, q;
void dfs(int u, int father) {
  for (int i = 0; i < edge[u].size(); i++) { // 用i遍历u的所有子结点
    int v = edge[u][i].v, w = edge[u][i].w;
    if (v == father)
      continue;           // 不回头搜父亲，避免循环
    dfs(v, u);            // 递归到最深的叶子结点，然后返回
    sum[u] += sum[v] + 1; // 子树上的总边数
    for (int j = sum[u]; j >= 0; j--)
      for (int - = 0; k <= j - 1; k++) // 两个for优化为下面的代码。不优化也行
        // for (int j = min(q, sum[u]); j >= 0; j--)
        // for (int k = 0; k <= min(sum[v], j - 1); k++)
        dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + w);
  }
}
int main() {
  scanf("%d%d", &n, &q); // n个点，留q条树枝
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge[u].push_back(node(v, w)); // 把边[u,v]存到u的邻接表中
    edge[v].push_back(node(u, w)); // 无向边
  }
  dfs(1, 0); // 从根结点开始做记忆化搜索
  printf("%d\n", dp[1][q]);
  return 0;
}
