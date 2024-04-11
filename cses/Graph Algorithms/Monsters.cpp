// 对 monsters 需要进行多源 BFS来讲时间复杂度从 O（n2m2）降低到 O（nm）
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"

vector<vector<char>> grid;
queue<pair<int, int>> monsterBfsQue; // first is y,second is x;
pair<int, int> startPoint;
vector<vector<int>> gridMonDist;
vector<vector<int>> gridDist;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string dir = "LURD";
string path = "";
int boundaryY = -1, boundaryX = -1;

bool bfs(int sy, int sx) {
  queue<pair<int, int>> q;
  q.push({sy, sx});
  gridDist[sy][sx] = 0;
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (grid[ny][nx] == 'B') {
        boundaryY = y, boundaryX = x;
        return true;
      }
      if (grid[ny][nx] == '.' && gridMonDist[ny][nx] > gridDist[y][x] + 1 &&
          gridDist[ny][nx] > gridDist[y][x] + 1) {
        gridDist[ny][nx] = gridDist[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  // 'B' is next to boundary squares
  grid.resize(n + 2, vector<char>(m + 2, 'B'));
  gridMonDist.resize(n + 2, vector<int>(m + 2, n * m + 1));
  gridDist.resize(n + 2, vector<int>(m + 2, n * m + 1));
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      cin >> grid[y][x];
      if (grid[y][x] == 'M') {
        monsterBfsQue.push({y, x});
        gridMonDist[y][x] = 0;
      } else if (grid[y][x] == 'A')
        startPoint.first = y, startPoint.second = x;
    }
  }

  while (!monsterBfsQue.empty()) {
    int y = monsterBfsQue.front().first, x = monsterBfsQue.front().second;
    monsterBfsQue.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if ((grid[ny][nx] == '.' || grid[ny][nx] == 'A') &&
          gridMonDist[ny][nx] > gridMonDist[y][x] + 1) {
        gridMonDist[ny][nx] = gridMonDist[y][x] + 1;
        monsterBfsQue.push({ny, nx});
      }
    }
  }

  if (bfs(startPoint.first, startPoint.second)) {
    cout << "YES" << endl;
    int y = boundaryY, x = boundaryX;
    while (!(y == startPoint.first && x == startPoint.second)) {
      for (int i = 0; i < 4; i++) {
        int py = y - dy[i], px = x - dx[i];
        if (gridDist[py][px] == gridDist[y][x] - 1) {
          path += dir[i];
          y = py, x = px;
          break;
        }
      }
    }
    reverse(path.begin(), path.end());
    cout << path.length() << endl;
    cout << path << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}