// 用stack来去掉dfs 的递归
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<char>> grid;
vector<vector<int>> gridMedicine;
vector<vector<int>> gridMaxE;
int sy, sx, ty, tx;
int h, w;
// 上右下左
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
void dfs() {
  if (gridMedicine[sy][sx] == 0) {
    cout << "No" << endl;
    return;
  }
  gridMaxE[sy][sx] = gridMedicine[sy][sx];
  stack<array<int, 3>> sk;
  sk.push({gridMaxE[sy][sx], sy, sx});
  while (!sk.empty()) {
    auto [e, y, x] = sk.top();
    sk.pop();
    // 由于取出时，gridMaxE有可能和 push
    // 进去时不一样了，所以尽量都在这里进行判断
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
      // 由于记录了gridMaxE，所以就没有必要记录吃没吃过药了
      if (ne > gridMaxE[ny][nx]) {
        sk.push({ne, ny, nx});
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
  grid.resize(h + 1, vector<char>(w + 1));
  gridMedicine.resize(h + 1, vector<int>(w + 1, 0));
  gridMaxE.resize(h + 1, vector<int>(w + 1, -1));
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
  dfs();
  return 0;
}