#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
char grid[201][201];
int gridMedicine[201][201];
int gridMaxE[201][201];
int sy, sx, ty, tx;
int h, w;
// 上右下左
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
void bfs() {
  priority_queue<array<int, 3>> pq;
  gridMaxE[sy][sx] = max(gridMedicine[sy][sx], 0);
  pq.push({gridMaxE[sy][sx], sy, sx});
  while (!pq.empty()) {
    auto [e, y, x] = pq.top();
    pq.pop();
    if (x == tx && y == ty) {
      cout << "Yes" << endl;
      return;
    }
    if (e == 0)
      continue;
    if (e < gridMaxE[y][x])
      continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > w || ny < 1 || ny > h || grid[ny][nx] == '#')
        continue;
      int ne = e - 1;
      if (gridMedicine[ny][nx] != 0) {
        ne = max(gridMedicine[ny][nx], ne);
      }
      if (ne > gridMaxE[ny][nx]) {
        pq.push({ne, ny, nx});
        gridMaxE[ny][nx] = ne;
      }
    }
  }
  cout << "No" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> h >> w;
  for (int line = 1; line <= h; line++) {
    for (int column = 1; column <= w; column++) {
      cin >> grid[line][column];
      if (grid[line][column] == 'S') {
        sy = line;
        sx = column;
      }
      if (grid[line][column] == 'T') {
        ty = line;
        tx = column;
      }
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r, c, e;
    cin >> r >> c >> e;
    gridMedicine[r][c] = e;
  }

  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++)
      gridMaxE[i][j] = -0x3f;
  }
  bfs();
  return 0;
}