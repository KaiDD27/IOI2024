// dfs穷举回溯超时，虽然有记忆化，但是不符合动态规划状态转移要求
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
deque<int> pathLongest;
deque<int> pathTmp;
vector<int> dp;
int n, m;
void dfs(int a) {
  dp[a] = pathTmp.size();
  if (a == n) {
    if (pathTmp.size() > pathLongest.size()) {
      pathLongest.clear();
      pathLongest = pathTmp;
    }
    return;
  }
  for (auto b : adj[a]) {
    if (pathTmp.size() + 1 <= dp[b])
      continue;
    pathTmp.push_back(b);
    dfs(b);
    pathTmp.pop_back();
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  adj.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  pathTmp.push_back(1);

  dfs(1);

  if (pathLongest.size() == 0)
    cout << "IMPOSSIBLE";
  else {
    cout << pathLongest.size() << endl;
    for (auto pi : pathLongest)
      cout << pi << " ";
  };

  return 0;
}