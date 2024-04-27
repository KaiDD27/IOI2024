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

pair<int, int> findNextblock(int x, int y) {
  for (int i = y; i <= h; i++) {
    for (int j = x; j <= w; j++) {
      if (grid[i][j] == false)
        return {j, i};
    }
  }
  return {x, y};
}

void dfs(int x, int y) {
  if (x > w) {
    x = 1;
    y++;
  }
  if (y == h + 1) {
    cout << "Yes" << endl;
    exit(0);
  }                         // 放完了
  if (grid[y][x] == true) { // 被放过了就直接搜下一个
    dfs(x + 1, y);
    return;
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
          dfs(x + 1, y);
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