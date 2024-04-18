// 有向图强连通分量
// 和Planets Cycles有点类似，但因为不是功能图，
// 所以不能简单的用visit的三种状态去判断是否在一个环里
// 需要用 Tarjan 算法，实现参见算法竞赛下册

#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
stack<int> sk;
// strongly connected component
vector<int> sCComponetLabel;
vector<int> oldestAncestorsConnected, num;
int dfsN = 0;
vector<vector<int>> adj;
int sccCnt = 0;

void dfs(int a) {
  sk.push(a);
  oldestAncestorsConnected[a] = num[a] = ++dfsN;
  for (auto b : adj[a]) {
    if (num[b] == -1) {
      dfs(b);
      oldestAncestorsConnected[a] =
          min(oldestAncestorsConnected[a], oldestAncestorsConnected[b]);
    } else if (sCComponetLabel[b] == -1)
      // 如已独立出去了，则a,b不能双连通
      // 否则num[b]可能更老
      oldestAncestorsConnected[a] = min(oldestAncestorsConnected[a], num[b]);
  }
  if (oldestAncestorsConnected[a] == num[a]) {
    sCComponetLabel[a] = ++sccCnt;
    while (a != sk.top()) {
      sCComponetLabel[sk.top()] = sccCnt;
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
  adj.resize(n + 1);
  sCComponetLabel.resize(n + 1, -1);
  oldestAncestorsConnected.resize(n + 1, n + 1);
  num.resize(n + 1, -1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == -1)
      dfs(i);
  }

  cout << sccCnt << endl;
  for (int i = 1; i <= n; i++) {
    cout << sCComponetLabel[i] << " ";
  }
  return 0;
}