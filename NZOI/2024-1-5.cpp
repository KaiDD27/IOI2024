#include <array>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int N, M;
vector<int> t;           // 动态数组替换静态数组 t[100000]
vector<vector<int>> dp;  // 动态数组替换静态数组 dp[2005][2005]
vector<vector<int>> adj; // 动态数组替换静态数组 conn[100000]

void dfs(int node, int next, int p = -1) {
  int curr_next = next;
  for (int c : adj[node]) {
    if (c != p) {
      dfs(c, curr_next, node);
      curr_next = c;
    }
  }
  for (int m = 0; m <= M; m++) {
    dp[node][m] = min(dp[next][m],
                      t[node] + (m > t[node] ? dp[curr_next][m - t[node]] : 0));
  }
}

int main() {
  cin >> N >> M;
  t.resize(N);                                         // 调整 t 的大小
  dp.resize(N + 1, vector<int>(M + 1, 2 * 2000 + 10)); // 调整 dp 的大小并初始化
  adj.resize(N);                                       // 调整 conn 的大小

  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(0, N, -1);
  cout << dp[0][M] << endl;

  return 0;
}

/*
5 5
3 1 5 1 2
0 1
1 3
0 2
1 4
*/