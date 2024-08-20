#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

// Constants
const int X = 0, Y = 1, R = 2;

// Global variables
vector<array<double, 3>> trees;
vector<vector<pair<double, ll>>> adj;
double startX, startY, endX, endY;
ll numTrees;

// Function implementations
double distanceBetweenPoints(const array<double, 3> &a,
                             const array<double, 3> &b) {
  double dx = a[X] - b[X];
  double dy = a[Y] - b[Y];
  double distance = sqrt(dx * dx + dy * dy) - a[R] - b[R];
  return max(0.0, distance);
}

double shortestPath() {
  vector<double> dist(numTrees + 2, 1e8);
  dist[0] = 0;
  queue<ll> q;
  q.push(0);

  while (!q.empty()) {
    ll current = q.front();
    q.pop();

    for (const auto &[distance, neighbor] : adj[current]) {
      if (dist[current] + distance < dist[neighbor]) {
        dist[neighbor] = dist[current] + distance;
        q.push(neighbor);
      }
    }
  }

  return dist[numTrees + 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Input
  cin >> startX >> startY >> endX >> endY >> numTrees;
  trees.resize(numTrees + 2);
  adj.resize(numTrees + 2);

  trees[0] = {startX, startY, 0};
  trees[numTrees + 1] = {endX, endY, 0};

  for (int i = 1; i <= numTrees; i++) {
    cin >> trees[i][X] >> trees[i][Y] >> trees[i][R];
  }

  // Build adjacency list
  for (int i = 0; i <= numTrees + 1; i++) {
    for (int j = 0; j <= numTrees + 1; j++) {
      adj[i].push_back({distanceBetweenPoints(trees[i], trees[j]), j});
    }
  }

  // Output result
  cout << fixed << setprecision(6) << shortestPath() << "\n";

  return 0;
}
