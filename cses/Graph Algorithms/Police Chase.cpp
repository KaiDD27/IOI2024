#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> currAdj, initialAdj;
vector<int> pre;
int n, m;
bool bfs() {
  queue<int> q;
  q.push(1);
  // 置为 0，便于后面找最小割
  pre[1] = 0;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int b = 1; b <= n; b++) {
      if (pre[b] == -1 && currAdj[a][b] > 0) {
        pre[b] = a;
        q.push(b);
      }
    }
  }
  return pre[n] != -1;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  cin >> n >> m;
  pre.resize(n + 1, -1);
  currAdj.resize(n + 1, vector<int>(n + 1, 0));
  initialAdj.resize(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    currAdj[a][b]++;
    currAdj[b][a]++;
    initialAdj[a][b]++;
    initialAdj[b][a]++;
  }
  int maxFlow = 0;
  while (bfs()) {
    int currFlow = INT_MAX;
    int b = n;
    while (b != 1) {
      int a = pre[b];
      currFlow = min(currFlow, currAdj[a][b]);
      b = a;
    }
    b = n;
    while (b != 1) {
      int a = pre[b];
      currAdj[a][b] -= currFlow;
      currAdj[b][a] += currFlow;
      b = a;
    }
    maxFlow += currFlow;
    fill(pre.begin(), pre.end(), -1);
  }
  cout << maxFlow << endl;
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      if (pre[a] != -1 && initialAdj[a][b] > 0 && pre[b] == -1)
        cout << a << " " << b << endl;
    }
  }
  return 0;
}