// Kruskal算法
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
// 0为 c，1 为 a，2 为 b
vector<array<int, 3>> edge;
vector<int> link;
int find_set(int a) {
  if (a == link[a])
    return a;
  // 路径压缩，不然会超时
  return link[a] = find_set(link[a]);
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  edge.resize(m);
  for (auto &[c, a, b] : edge)
    cin >> a >> b >> c;
  sort(edge.begin(), edge.end());
  link.resize(n + 1);
  for (int i = 1; i <= n; i++)
    link[i] = i;
  ll totalCost = 0, cnt = 0;
  for (auto [c, a, b] : edge) {
    int e1 = find_set(a);
    int e2 = find_set(b);
    if (e1 == e2)
      continue;
    link[e1] = e2;
    totalCost += c;
    cnt++;
  }
  if (cnt == n - 1)
    cout << totalCost << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}