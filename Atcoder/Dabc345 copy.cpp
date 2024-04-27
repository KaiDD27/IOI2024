#include <algorithm>
#include <array>
#include <iostream>

#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<array<int, 2>> ab;
vector<vector<bool>> grid;
vector<bool> abUsed;
int n, h, w;

bool ck(int x, int y, int a, int b) {
  for (int i = y; i <= y + b - 1; i++) {
    for (int j = x; j <= x + a - 1; j++) {
      if (grid[i][j] == true) {
        return false;
      }
    }
  }
  return true;
}

void putTile(int x, int y, int a, int b, bool putOrRemove) {
  for (int i = y; i <= y + b - 1; i++) {
    for (int j = x; j <= x + a - 1; j++) {
      grid[i][j] = putOrRemove;
    }
  }
  return;
}

void findNextblock(int &nx, int &ny) {
  for (int i = ny; i <= h; i++) {
    for (int j = nx; j <= w; j++) {
      if (grid[i][j] == false) {
        nx = j;
        ny = i;
        return;
      }
    }
  }
}

void dfs(int x, int y) {
  bool flag = false;
  for (int i = y; i <= h; i++) {
    for (int j = x; j <= w; j++) {
      if (grid[i][j] == false) {
        x = j;
        y = i;
        flag = true;
        break;
      }
      if (j == w)
        x = 1;
    }
    if (flag == true)
      break;
  }
  if (grid[y][x] == true) {
    cout << "Yes" << endl;
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    if (abUsed[i] == false) {
      int a = ab[i][0], b = ab[i][1];
      for (int j = 0; j <= 1; j++) {
        swap(a, b);
        if (x + a - 1 > w || y + b - 1 > h)
          continue;
        if (ck(x, y, a, b)) {
          putTile(x, y, a, b, true);
          abUsed[i] = true;
          dfs(x, y);
          putTile(x, y, a, b, false);
          abUsed[i] = false;
        }
        if (a == b)
          break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> h >> w;
  ab.resize(n + 1);
  grid.resize(h + 1, vector<bool>(w + 1));
  abUsed.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> ab[i][0] >> ab[i][1];
  dfs(1, 1);
  cout << "No";
  return 0;
}