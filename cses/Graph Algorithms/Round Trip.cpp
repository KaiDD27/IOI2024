#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<vector<int>> adj;
vector<int> pre;
vector<bool> visited;
vector<int> ans;
vector<int> pathOfStart, pathOfFin;
int start = 0, fin = 0;

bool dfs(int i) {
  for (auto ai : adj[i]) {
    if (visited[ai] && ai != pre[i]) {
      start = ai;
      fin = i;
      return true;
    } else if (!visited[ai]) {
      visited[ai] = true;
      pre[ai] = i;
      if (dfs(ai))
        return true;
    }
  }
  return false;
}

void printPath(int s, int f) {
  while (s != 0) {
    pathOfStart.push_back(s);
    s = pre[s];
  }
  reverse(pathOfStart.begin(), pathOfStart.end());
  while (f != 0) {
    pathOfFin.push_back(f);
    f = pre[f];
  }
  reverse(pathOfFin.begin(), pathOfFin.end());
  int begin = 0;
  for (int i = 0; i < pathOfFin.size() && i < pathOfStart.size(); i++) {
    if (pathOfStart[i] != pathOfFin[i])
      break;
    begin = i;
  }
  for (int i = begin; i < pathOfFin.size(); i++)
    ans.push_back(pathOfFin[i]);
  for (int i = pathOfStart.size() - 1; i >= 0; i--) {
    ans.push_back(pathOfStart[i]);
    if (pathOfStart[i] == pathOfStart[begin])
      break;
  }
  cout << ans.size() << endl;
  for (auto ai : ans)
    cout << ai << " ";
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  pre.resize(n + 1);
  adj.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      if (dfs(i)) {
        printPath(start, fin);
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}