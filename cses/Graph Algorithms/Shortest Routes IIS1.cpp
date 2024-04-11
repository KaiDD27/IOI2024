//  Floyd-warshall On3,注意两点可能有多条路,不要忘了初始化自己到自己的 dist为 0
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const ll INF = 1e14 + 10;
vector<vector<ll>> dist;
vector<pair<int, int>> query;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m, q;
  cin >> n >> m >> q;
  dist.resize(n + 1, vector<ll>(n + 1, INF));
  query.resize(q);

  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }

  for (auto &qi : query) {
    cin >> qi.first >> qi.second;
  }

  for (int i = 1; i <= n; i++) {
    for (int y = 1; y <= n; y++) {
      for (int x = 1; x <= n; x++) {
        if (dist[i][x] != INF && dist[y][i] != INF)
          dist[y][x] = min(dist[y][x], dist[y][i] + dist[i][x]);
      }
    }
  }

  for (auto qi : query) {
    if (dist[qi.first][qi.second] == INF)
      cout << "-1" << endl;
    else
      cout << dist[qi.first][qi.second] << endl;
  }
  return 0;
}