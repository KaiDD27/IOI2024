#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<char>> p;
queue<pair<int, int>> q;
pair<int, int> startPos, finPos;
// 左上右下-LURD
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool bfs(pair<int, int> pos) {
  visited[pos.first][pos.second] = true;
  q.push(pos);
  while (!q.empty()) {
    pair<int, int> topPos = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newY = topPos.first + dy[i], newX = topPos.second + dx[i];
      if ((grid[newY][newX] == '.' || grid[newY][newX] == 'B') &&
          visited[newY][newX] == false) {
        switch (i) {
        case 0:
          p[newY][newX] = 'L';
          break;
        case 1:
          p[newY][newX] = 'U';
          break;
        case 2:
          p[newY][newX] = 'R';
          break;
        case 3:
          p[newY][newX] = 'D';
          break;
        }
        visited[newY][newX] = true;
        q.push({newY, newX});
        if (grid[newY][newX] == 'B') {
          return true;
        }
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
  grid.resize(n + 2, vector<char>(m + 2, '#'));
  visited.resize(n + 2, vector<bool>(m + 2, false));
  p.resize(n + 2, vector<char>(m + 2));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        startPos = {i, j};
      if (grid[i][j] == 'B')
        finPos = {i, j};
    }
  }
  int length = 0;
  string strPath = "";
  if (bfs(startPos)) {
    int y = finPos.first, x = finPos.second;
    while (!(y == startPos.first && x == startPos.second)) {
      strPath += p[y][x];
      length++;
      switch (p[y][x]) {
      case 'L':
        y -= dy[0];
        x -= dx[0];
        break;
      case 'U':
        y -= dy[1];
        x -= dx[1];
        break;
      case 'R':
        y -= dy[2];
        x -= dx[2];
        break;
      case 'D':
        y -= dy[3];
        x -= dx[3];
        break;
      }
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