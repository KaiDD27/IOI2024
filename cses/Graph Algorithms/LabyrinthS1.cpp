#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
int n, m;
vector<vector<char>> grid;
vector<vector<int>> dist;
vector<vector<char>> path;
// 左上右下-LURD
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string dir = "LURD";

void bfs(int sy, int sx) {
  queue<pair<int, int>> q;
  q.push({sy, sx});
  dist[sy][sx] = 0;
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (grid[ny][nx] == '#' || dist[ny][nx] != -1)
        continue;
      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny, nx});
      if (grid[ny][nx] == 'B') {
        return;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  grid.resize(n + 2, vector<char>(m + 2, '#'));
  dist.resize(n + 2, vector<int>(m + 2, -1));
  int sx = 0, sy = 0, ex = 0, ey = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        sy = i, sx = j;
      if (grid[i][j] == 'B')
        ey = i, ex = j;
    }
  }
  bfs(sy, sx);
  if (dist[ey][ex] == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << dist[ey][ex] << "\n";
    string path;
    while (ex != sx || ey != sy) {
      for (int i = 0; i < 4; i++) {
        int px = ex - dx[i], py = ey - dy[i];
        if (grid[py][px] == '#')
          continue;
        if (dist[py][px] == dist[ey][ex] - 1) {
          path += dir[i];
          ex = px, ey = py;
          break;
        }
      }
    }
    reverse(path.begin(), path.end());
    cout << path << "\n";
  }
  return 0;
}