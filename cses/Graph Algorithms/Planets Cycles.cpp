// 做为函数图（功能图）只包含两种 component：1.任意个tree+一个cycle 2.一个cycle
// tree 上节点到fin点距离就是解；cycle的长度就是 cycle 上节点的解
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<int> tNum;
vector<int> teleport;
vector<int> inDegree;
// 0代表未访问，1 代表访问中，2 访问结束
vector<int> visited;

void dfs(int a) {
  visited[a] = 1;
  int b = teleport[a];
  if (visited[b] == 0)
    dfs(b);
  else if (visited[b] == 1) {
    // 要记录步数，要记录层级
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  teleport.resize(n + 1);
  tNum.resize(n + 1);
  inDegree.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> teleport[i];
    inDegree[teleport[i]]++;
  }

  for (int i = 1; i <= n; i++)
    if (inDegree[i] == 0)
      dfs(i);
  // 剩下的只可能是纯环
  for (int i = 1; i <= n; i++)
    if (visited[i] == 0)
      dfs(i);

  return 0;
}