#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  vector<long long> dist(n + 1, INF);
  vector<int> p(n + 1, -1);
  int x = -1;

  for (int i = 0; i < n; i++) {
    for (auto e : edges) {
      int a, b, c;
      tie(a, b, c) = e;
      if (i == n - 1) {
        if (dist[a] + c < dist[b]) {
          dist[b] = dist[a] + c;
          p[b] = a;
          x = b;
        }
      } else {
        if (dist[a] + c < dist[b]) {
          dist[b] = dist[a] + c;
        }
      }
    }
  }

  if (x == -1) {
    cout << "NO" << endl;
  } else {
    for (int i = 0; i < n; i++)
      x = p[x];

    vector<int> cycle;
    for (int v = x;; v = p[v]) {
      cycle.push_back(v);
      if (v == x && cycle.size() > 1)
        break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (int v : cycle)
      cout << v << ' ';
    cout << endl;
  }
}