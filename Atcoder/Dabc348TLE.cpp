// dfs递归调用太多层，超时了
#include <algorithm>
#include <array>
#include <iostream>
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
bool dfs(int x, int y, int e) {
  if (x == tx && y == ty)
    return true;
  if (e == 0 && gridMedicine[y][x] == 0)
    return false;
  int medicine = gridMedicine[y][x];
  if (e < medicine) {
    e = medicine;
    gridMedicine[y][x] = 0;
  }
  gridMaxE[y][x] = gridMaxE[y][x] >= e ? gridMaxE[y][x] : e;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > w || ny < 1 || ny > h)
      continue;
    if (nx == tx && ny == ty)
      return true;
    if (grid[ny][nx] != '#' && e - 1 > gridMaxE[ny][nx] &&
        !(e - 1 == 0 && gridMedicine[ny][nx] == 0)) {
      if (dfs(nx, ny, e - 1))
        return true;
    }
  }
  gridMedicine[y][x] = medicine;
  return false;
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
  if (dfs(sx, sy, 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}