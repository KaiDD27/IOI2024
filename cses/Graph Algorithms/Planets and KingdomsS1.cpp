// 有向图强连通分量
// Kosaraju
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
stack<int> topologicalOrder;
vector<bool> visited;
// strongly connected component
vector<int> sCComponetLabel;
vector<vector<int>> adj, rAdj;
int sccCnt = 0;

void dfs(int a) {
  visited[a] = true;
  for (auto b : adj[a]) {
    if (visited[b] == false)
      dfs(b);
  }
  topologicalOrder.push(a);
  return;
}

void dfsRG(int a, int label) {
  sCComponetLabel[a] = label;
  for (auto b : rAdj[a]) {
    if (sCComponetLabel[b] == 0)
      dfsRG(b, label);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  visited.resize(n + 1);
  adj.resize(n + 1);
  rAdj.resize(n + 1);
  sCComponetLabel.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    rAdj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false)
      dfs(i);
  }

  while (!topologicalOrder.empty()) {
    auto a = topologicalOrder.top();
    topologicalOrder.pop();
    if (sCComponetLabel[a] == 0) {
      dfsRG(a, ++sccCnt);
    }
  }
  cout << sccCnt << endl;
  for (int i = 1; i <= n; i++) {
    cout << sCComponetLabel[i] << " ";
  }
  return 0;
}