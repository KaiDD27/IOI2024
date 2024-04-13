// bellman-ford的灵活应用
#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<array<int, 3>> edge;
vector<ll> dist;
vector<int> pre;
const ll INF = 1e15;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  dist.resize(n + 1, INF);
  pre.resize(n + 1, -1);
  edge.resize(m);
  int cycleStart = -1;
  for (auto &ei : edge)
    cin >> ei[0] >> ei[1] >> ei[2];
  // 由于本题只关心是否有负环而不关心 1 节点到
  // 所有节点的最短路径是否正确，所以dist[1] =
  // 0;初始化不是必须的，但是初始化肯定更保险
  dist[1] = 0;
  for (int i = 1; i <= n; i++) {
    cycleStart = -1;
    for (auto [a, b, c] : edge) {
      // 这里不能加上 "dist[a]!=INF && "到 if 里面，因为即使负环之间和 1
      // 没有连接，我们也是要去检测的，所以也不能用LLONG_MAX,因为这个加 正数 c
      // 会越界变负数导致判断出错

      if (dist[b] > dist[a] + c) {
        dist[b] = dist[a] + c;
        // 必须每一轮都更新前置，如果只在第 n
        // 轮更新可能导致后面打印时无法通过 n 次cycleStart =
        // pre[cycleStart];确保找到负环所在的节点，中间路径可能就断了
        pre[b] = a;
        cycleStart = b;
      }
    }
  }
  if (cycleStart == -1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  // 往回走 n 步，确保一定在负环上
  for (int i = 0; i < n; i++) {
    cycleStart = pre[cycleStart];
  }
  int cyclePre = pre[cycleStart];
  vector<int> cycle;
  cycle.push_back(cycleStart);
  while (cyclePre != cycleStart) {
    cyclePre = pre[cyclePre];
  }
  cycle.push_back(cycleStart);
  // 因为是有向图，所以一定要反转
  reverse(cycle.begin(), cycle.end());
  for (auto ci : cycle)
    cout << ci << " ";

  return 0;
}