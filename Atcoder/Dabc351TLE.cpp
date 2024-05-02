#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> s;
vector<vector<ll>> gridIndex;
vector<vector<bool>> gridVisited;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
ll h, w;
bool stop(ll y, ll x) {
  if (y < 0 || y > h - 1 || x < 0 || x > w - 1 || s[y][x] == '#') {
    return true;
  }
  for (int i = 0; i < 4; i++) {
    ll ny = y + dy[i];
    ll nx = x + dx[i];
    if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1)
      continue;
    if (s[ny][nx] == '#')
      return true;
  }
  return false;
}
void bfs(ll sy, ll sx, ll index) {
  queue<array<ll, 2>> q;
  q.push({sy, sx});
  gridIndex[sy][sx] = index;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if (stop(ny, nx) == false && gridIndex[ny][nx] == 0) {
        gridIndex[ny][nx] = index;
        q.push({ny, nx});
      }
    }
  }
}
ll bfsIndex(ll sy, ll sx, ll index) {
  ll cnt = 0;
  gridVisited[sy][sx] = true;
  cnt++;
  queue<array<ll, 2>> q;
  q.push({sy, sx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1 || s[ny][nx] == '#' ||
          gridVisited[ny][nx] == true)
        continue;
      else {
        gridVisited[ny][nx] = true;
        cnt++;
        if (gridIndex[ny][nx] == index) {
          q.push({ny, nx});
        }
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  cin >> h >> w;
  s.resize(h);
  gridIndex.resize(h, vector<ll>(w));
  for (auto &si : s) {
    cin >> si;
  }

  ll index = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (s[y][x] == '#')
        continue;
      if (stop(y, x) == false && gridIndex[y][x] == 0) {
        bfs(y, x, ++index);
      }
    }
  }
  ll ans = 1;
  index = 1;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (gridIndex[y][x] == index) {
        gridVisited.clear();
        gridVisited.resize(h, vector<bool>(w, false));
        ans = max(ans, bfsIndex(y, x, index));
        index++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}