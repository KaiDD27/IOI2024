// 有向图强连通分量
// 和Planets Cycles有点类似，但因为不是功能图，
// 所以不能简单的用visit的三种状态去判断是否在一个环里
// 需要用 Tarjan 算法，实现参见算法竞赛下册
// Tarjan 生成的SCC 的序号是拓扑排序逆序的
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> adj;
vector<int> num, oldestAncestorConnected, sCComponentLabel;
stack<int> sk;
int dfsN = 0;
int sCCCnt = 0;
void dfs(int a) {
  sk.push(a);
  oldestAncestorConnected[a] = num[a] = ++dfsN;
  for (auto b : adj[a]) {
    if (num[b] == -1) {
      dfs(b);
      oldestAncestorConnected[a] =
          min(oldestAncestorConnected[a], oldestAncestorConnected[b]);
    } else if (sCComponentLabel[b] == -1) {
      oldestAncestorConnected[a] = min(oldestAncestorConnected[a], num[b]);
    }
  }
  if (oldestAncestorConnected[a] == num[a]) {
    sCComponentLabel[a] = ++sCCCnt;
    while (sk.top() != a) {
      sCComponentLabel[sk.top()] = sCCCnt;
      sk.pop();
    }
    sk.pop();
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  adj.resize(2 * m + 1);
  num.resize(2 * m + 1, -1);
  oldestAncestorConnected.resize(2 * m + 1, 2 * m + 1);
  sCComponentLabel.resize(2 * m + 1, -1);
  for (int i = 0; i < n; i++) {
    char symbolA, symbolB;
    int a, b;
    cin >> symbolA >> a >> symbolB >> b;
    int sA = symbolA == '+' ? 1 : 0;
    int sB = symbolB == '+' ? 1 : 0;
    adj[(1 - sA) * m + a].push_back(sB * m + b);
    adj[(1 - sB) * m + b].push_back(sA * m + a);
  }
  for (int i = 1; i <= 2 * m; i++) {
    if (num[i] == -1)
      dfs(i);
  }

  for (int i = 1; i <= m; i++) {
    if (sCComponentLabel[i] == sCComponentLabel[i + m]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  // SCC 的序号是拓扑排序逆序的
  for (int i = 1; i <= m; i++) {
    if (sCComponentLabel[i] > sCComponentLabel[i + m]) {
      cout << "+ ";
    } else {
      cout << "- ";
    }
  }
  return 0;
}