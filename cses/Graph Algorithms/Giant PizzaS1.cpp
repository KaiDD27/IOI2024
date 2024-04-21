// 有向图强连通分量
// Kosaraju 生成的SCC的序号是拓扑排序的
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj, rAdj;
stack<int> sk;
vector<bool> visited;
vector<int> componentLabel;
void dfs(int a) {
  visited[a] = true;
  for (auto b : adj[a]) {
    if (visited[b] == false)
      dfs(b);
  }
  sk.push(a);
  return;
}
void rDfs(int a, int cnt) {
  visited[a] = true;
  componentLabel[a] = cnt;
  for (auto b : rAdj[a]) {
    if (visited[b] == false)
      rDfs(b, cnt);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  // 0到 m-1 表示不喜欢 topping，m到 2m-1 表示喜欢 topping
  adj.resize(2 * m);
  rAdj.resize(2 * m);
  visited.resize(2 * m);
  componentLabel.resize(2 * m);
  for (int i = 0; i < n; i++) {
    char symbolA, symbolB;
    int a, b;
    cin >> symbolA >> a >> symbolB >> b;
    a--;
    b--;
    if (symbolA == '+')
      a += m;
    if (symbolB == '+')
      b += m;
    adj[(a + m) % (2 * m)].push_back(b);
    rAdj[b].push_back((a + m) % (2 * m));
    adj[(b + m) % (2 * m)].push_back(a);
    rAdj[a].push_back((b + m) % (2 * m));
  }

  for (int i = 0; i < 2 * m; i++) {
    if (visited[i] == false)
      dfs(i);
  }
  fill(visited.begin(), visited.end(), false);
  int componentCnt = 0;
  while (!sk.empty()) {
    auto a = sk.top();
    sk.pop();
    if (visited[a] == false)
      rDfs(a, ++componentCnt);
  }

  for (int i = 0; i < m; i++) {
    if (componentLabel[i] == componentLabel[i + m]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (componentLabel[i] < componentLabel[i + m])
      cout << "+ ";
    else
      cout << "- ";
  }
  return 0;
}