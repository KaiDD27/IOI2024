#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define pii pair<int, int>

int n, m;
char grid[1005][1005];
int monster_dist[1005][1005], my_dist[1005][1005];
int prev_x[1005][1005], prev_y[1005][1005];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string dir = "ULDR";

int main() {
  cin >> n >> m;
  queue<pii> q;
  pii start;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'M') {
        q.push({i, j});
        monster_dist[i][j] = 0;
      } else
        monster_dist[i][j] = 1e9;

      if (grid[i][j] == 'A')
        start = {i, j};
      my_dist[i][j] = 1e9;
    }
  }

  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x.first + dx[i], ny = x.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (grid[nx][ny] == '#')
        continue;
      if (monster_dist[nx][ny] > monster_dist[x.first][x.second] + 1) {
        monster_dist[nx][ny] = monster_dist[x.first][x.second] + 1;
        q.push({nx, ny});
      }
    }
  }

  q.push(start);
  my_dist[start.first][start.second] = 0;

  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x.first + dx[i], ny = x.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        cout << "YES\n";
        cout << my_dist[x.first][x.second] + 1 << "\n";
        string ans;
        while (x != start) {
          int px = prev_x[x.first][x.second], py = prev_y[x.first][x.second];
          if (x.first == px + 1)
            ans += 'D';
          if (x.first == px - 1)
            ans += 'U';
          if (x.second == py + 1)
            ans += 'R';
          if (x.second == py - 1)
            ans += 'L';
          x = {px, py};
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
        return 0;
      }
      if (grid[nx][ny] == '#')
        continue;
      if (my_dist[nx][ny] > my_dist[x.first][x.second] + 1 &&
          my_dist[x.first][x.second] + 1 < monster_dist[nx][ny]) {
        my_dist[nx][ny] = my_dist[x.first][x.second] + 1;
        prev_x[nx][ny] = x.first;
        prev_y[nx][ny] = x.second;
        q.push({nx, ny});
      }
    }
  }

  cout << "NO\n";
}