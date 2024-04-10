#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> teamIdx;
bool dfs(int i) {
  for (auto ai : adj[i]) {
    if (teamIdx[ai] == 0) {
      teamIdx[ai] = (teamIdx[i] == 1 ? 2 : 1);
      if (dfs(ai) == false)
        return false;
    } else if (teamIdx[ai] == teamIdx[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  teamIdx.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (teamIdx[i] == 0) {
      teamIdx[i] = 1;
      if (dfs(i) == false) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << teamIdx[i] << " ";
  return 0;
}