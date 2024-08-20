#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<array<double, 3>> tree;
vector<vector<pair<double, ll>>> adj;
double sX, sY, tX, tY;
const int X = 0, Y = 1, R = 2;
ll n;
double distanceOfTowP(const array<double, 3> &a, const array<double, 3> &b) {
  double ret =
      sqrt((a[X] - b[X]) * (a[X] - b[X]) + (a[Y] - b[Y]) * (a[Y] - b[Y])) -
      a[R] - b[R];
  if (ret > 0)
    return ret;
  else
    return 0;
}
// BFS求解最短路径
double shortestPath() {
  vector<double> dist(n + 2, 1e8);
  dist[0] = 0;
  queue<ll> q;
  q.push(0);
  while (!q.empty()) {
    ll idA = q.front();
    q.pop();
    for (auto [distAB, idB] : adj[idA]) {
      if (dist[idA] + distAB < dist[idB]) {
        dist[idB] = dist[idA] + distAB;
        q.push(idB);
      }
    }
  }
  return dist[n + 1];
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> sX >> sY >> tX >> tY;
  cin >> n;
  tree.resize(n + 2);
  adj.resize(n + 2);
  tree[0][X] = sX, tree[0][Y] = sY, tree[n + 1][X] = tX, tree[n + 1][Y] = tY;
  for (int i = 1; i <= n; i++)
    cin >> tree[i][X] >> tree[i][Y] >> tree[i][R];
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      adj[i].push_back({distanceOfTowP(tree[i], tree[j]), j});
    }
  }
  cout << fixed << setprecision(6) << shortestPath() << endl;

  return 0;
}