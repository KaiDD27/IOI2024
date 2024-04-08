#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<char>> grid;
vector<vector<int>> path;
queue<pair<int, int>> q;
int startX, startY, finX, finY;
// 左上右下-LURD
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string dir = "LURD";
void bfs(int sy, int sx) {
  q.push({sy, sx});
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newY = y + dy[i], newX = x + dx[i];
      if (grid[newY][newX] != '#' && path[newY][newX] == -1) {
        path[newY][newX] = i;
        q.push({newY, newX});
        if (grid[newY][newX] == 'B') {
          return;
        }
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  grid.resize(n + 2, vector<char>(m + 2, '#'));
  path.resize(n + 2, vector<int>(m + 2, -1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        startY = i, startX = j;
      if (grid[i][j] == 'B')
        finY = i, finX = j;
    }
  }
  int length = 0;
  string strPath = "";
  bfs(startY, startX);
  if (path[finY][finX] != -1) {
    int y = finY, x = finX;
    while (!(y == startY && x == startX)) {
      int tmp = path[y][x];
      strPath += dir[tmp];
      length++;
      y -= dy[tmp];
      x -= dx[tmp];
    }
    cout << "YES" << endl;
    cout << length << endl;
    reverse(strPath.begin(), strPath.end());
    cout << strPath << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}