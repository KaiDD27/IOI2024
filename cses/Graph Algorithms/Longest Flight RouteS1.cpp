// 拓扑排序（bfs）+动态规划(拓扑排序确保了动态规划状态转移可以递推成功)
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> path;
vector<int> dp;
vector<int> inAdjCnt;
vector<bool> visited;
queue<int> q;
vector<int> pre;
int n, m;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  adj.resize(n + 1);
  dp.resize(n + 1, -1);
  inAdjCnt.resize(n + 1);
  visited.resize(n + 1, false);
  pre.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    inAdjCnt[b]++;
  }
  dp[1] = 0;

  for (int i = 1; i <= n; i++) {
    if (inAdjCnt[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      if (dp[a] != -1 && dp[b] < dp[a] + 1) {
        dp[b] = dp[a] + 1;
        pre[b] = a;
      }
      if (--inAdjCnt[b] == 0)
        q.push(b);
    }
  }
  vector<int> ans;
  if (dp[n] == -1)
    cout << "IMPOSSIBLE";
  else {
    cout << dp[n] + 1 << endl;
    int tmp = n;
    while (tmp != 1) {
      ans.push_back(tmp);
      tmp = pre[tmp];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (auto ai : ans)
      cout << ai << " ";
  }

  return 0;
}