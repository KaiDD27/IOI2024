#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const ll NINF = -1e14 - 10;
vector<array<int, 3>> edge;
vector<ll> dist;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  edge.resize(m);
  dist.resize(n + 1, NINF);
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    edge[i].at(0) = a, edge[i][1] = b, edge[i][2] = x;
  }
  dist[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (auto ei : edge)
      dist[ei[1]] = max(dist[ei[1]], dist[ei[0]] + ei[2]);
  }

  for (auto ei : edge) {
    if (dist[ei[0]] + ei[2] > dist[ei[1]]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << dist[n] << endl;
  return 0;
}