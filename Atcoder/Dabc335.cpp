#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dir = "RDLU";
vector<vector<string>> grid;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  grid.resize(n + 2, vector<string>(n + 2, "0"));
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
        grid[i][j] = "#";
    }
  }
  grid[(n + 1) / 2][(n + 1) / 2] = "T";
  int x = 1, y = 1;
  int currDir = 0;
  int part = 1;
  grid[1][1] = "1";
  while (1) {
    if (grid[y + dy[currDir]][x + dx[currDir]] == "T") {
      break;
    }
    if (grid[y + dy[currDir]][x + dx[currDir]] != "0") {
      currDir++;
      currDir = currDir % 4;
    } else {
      x += dx[currDir];
      y += dy[currDir];
      part++;
      grid[y][x] = to_string(part);
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
        continue;
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}