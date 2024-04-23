#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> outDegree, inDegree;
vector<int> euler;
void dfs(int a) {
  while (!adj[a].empty()) {
    int b = adj[a].back();
    adj[a].pop_back();
    dfs(b);
  }
  euler.push_back(a);
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  outDegree.resize(n + 1);
  inDegree.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    outDegree[a]++;
    inDegree[b]++;
  }

  if ((outDegree[1] - inDegree[1] != 1) || (outDegree[n] - inDegree[n] != -1)) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (outDegree[i] != inDegree[i]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  dfs(1);

  // m条边，则会经过m+1个点如果还有边没有访问到，则无解.
  if (euler.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  reverse(euler.begin(), euler.end());

  for (auto ei : euler)
    cout << ei << " ";
  cout << endl;
  return 0;
}