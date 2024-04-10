#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<bool> visited;
vector<int> components;
void dfs(int i) {
  visited[i] = true;
  for (auto ai : adj[i]) {
    if (visited[ai] == false)
      dfs(ai);
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      components.push_back(i);
      dfs(i);
    }
  }
  int numRoads = components.size() - 1;
  cout << numRoads << endl;
  for (int i = 0; i < numRoads; i++) {
    cout << components[i] << " " << components[i + 1] << endl;
  }
  return 0;
}