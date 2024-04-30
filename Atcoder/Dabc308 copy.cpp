#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> grid;
vector<vector<bool>> gridVisited;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
// string dir = "RDLU";
string strSk = "snuke";
const ll MOD = 5;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int h, w;
  cin >> h >> w;
  gridVisited.resize(h + 2, vector<bool>(w + 2, false));
  string strWall = "";
  for (int i = 0; i <= w + 1; i++)
    strWall.push_back('#');
  grid.push_back(strWall);
  for (int i = 1; i <= h; i++) {
    string strTmp;
    cin >> strTmp;
    grid.push_back('#' + strTmp + '#');
  }
  grid.push_back(strWall);

  if (grid[1][1] != 's') {
    cout << "No" << endl;
    return 0;
  }
  priority_queue<array<ll, 4>> q;
  q.push({2, 1, 1, 0});
  gridVisited[1][1] = true;

  while (!q.empty()) {
    auto [sq, x, y, pos] = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if (grid[ny][nx] == strSk[(pos + 1) % MOD] &&
          gridVisited[ny][nx] == false) {
        gridVisited[ny][nx] = true;
        q.push({nx * nx + ny * ny, nx, ny, (pos + 1) % MOD});
        if (nx == w && ny == h) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}