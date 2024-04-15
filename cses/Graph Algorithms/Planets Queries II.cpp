// 函数图（功能图）+二进制跳跃
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const int MAXD = 18;
vector<int> teleport;
vector<array<int, MAXD>> dp;
vector<int> inDegree;
// 0代表未访问，1 代表访问中，2 访问结束
vector<int> visited;
vector<int> height;
vector<int> Fin;
void dfs(int a) {
  visited[a] = 1;
  int b = teleport[a];
  if (visited[b] == 0)
    dfs(b);
  else if (visited[b] == 1) {
    visited[a] = 2;
    height[a] = 1;
    Fin[a] = a;
    return;
  }
  visited[a] = 2;
  height[a] = height[b] + 1;
  Fin[a] = Fin[b];
  return;
}
int jump(int a, int k) {
  for (int i = 0; i < MAXD; i++) {
    if (k & (1 << i))
      a = dp[a][i];
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, q;
  cin >> n >> q;
  teleport.resize(n + 1);
  dp.resize(n + 1);
  inDegree.resize(n + 1);
  visited.resize(n + 1);
  height.resize(n + 1);
  Fin.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> teleport[i];
    inDegree[teleport[i]]++;
    dp[i][0] = teleport[i];
  }
  // 生成 parent matrix
  for (int i = 1; i < MAXD; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = dp[dp[j][i - 1]][i - 1];

  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0)
      dfs(i);
  }
  // 一个连同分量所有的节点都在环上，则只能在这被遍历到
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0)
      dfs(i);
  }

  for (int i = 0, a = 0, b = 0; i < q; i++) {
    cin >> a >> b;
    if (Fin[a] != Fin[b]) {
      cout << "-1" << endl;
      continue;
    }
    int k = height[a] - height[b];
    if (k >= 0 && jump(a, k) == b) {
      cout << k << endl;
    } else {
      k = height[a] - 1 + (teleport[Fin[a]] == Fin[a] ? 0 : 1);
      a = teleport[Fin[a]];
      int diff = height[a] - height[b];
      if (diff >= 0 && jump(a, diff) == b)
        cout << k + diff << endl;
      else
        cout << "-1" << endl;
    }
  }
  return 0;
}
