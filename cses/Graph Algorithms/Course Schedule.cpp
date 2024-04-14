#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<bool> visited;
vector<vector<int>> adj;
vector<int> courseOrder;
// 只需要统计入度就行，这样才能满足时间复杂度，当入度中未访问节点数为 0
// 时，就可以访问了
vector<int> inAdjUnvistedCnt;
int n, m;
bool bfs(int a) {
  visited[a] = true;
  courseOrder.push_back(a);
  if (courseOrder.size() == n)
    return true;
  queue<int> q;
  q.push(a);
  while (!q.empty()) {
    a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      inAdjUnvistedCnt[b]--;
      if (visited[b] == false && inAdjUnvistedCnt[b] == 0) {
        visited[b] = true;
        courseOrder.push_back(b);
        if (courseOrder.size() == n)
          return true;
        q.push(b);
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  cin >> n >> m;
  visited.resize(n + 1);
  adj.resize(n + 1);
  inAdjUnvistedCnt.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    inAdjUnvistedCnt[b]++;
  }
  for (int i = 1; i <= n; i++) {
    if (inAdjUnvistedCnt[i] == 0 && visited[i] == false)
      if (bfs(i) == true)
        break;
  }
  if (courseOrder.size() != n)
    cout << "IMPOSSIBLE" << endl;
  else {
    for (auto ci : courseOrder)
      cout << ci << " ";
  }
  return 0;
}