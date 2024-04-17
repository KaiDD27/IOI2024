// dfs(1) 按照出度和入度分别来一遍，看看是否是全覆盖
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj, inAdj;
vector<bool> visited;
void dfs(int a, vector<vector<int>> &adj) {
  visited[a] = true;
  for (auto b : adj[a]) {
    if (visited[b] == false) {
      dfs(b, adj);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  inAdj.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    inAdj[b].push_back(a);
  }
  dfs(1, adj);
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      cout << "NO" << endl;
      cout << "1"
           << " " << i << endl;
      return 0;
    }
  }
  visited.clear();
  visited.resize(n + 1);
  dfs(1, inAdj);
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      cout << "NO" << endl;
      cout << i << " 1" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}