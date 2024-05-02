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
bool valid(ll y, ll x) {
  if (y < 0 || y > h - 1 || x < 0 || x > w - 1 || s[y][x] == '#')
    return false;
  return true;
}
ll bfs(ll sy, ll sx, ll index) {
  ll cnt = 0;
  queue<array<ll, 2>> q;
  q.push({sy, sx});
  gridIndex[sy][sx] = index;
  cnt++;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if (valid(ny, nx) == false)
        continue;
      if (stop(ny, nx) == true && gridIndex[ny][nx] != index) {
        gridIndex[ny][nx] = index;
        cnt++;
      } else if (gridIndex[ny][nx] == 0) {
        gridIndex[ny][nx] = index;
        q.push({ny, nx});
        cnt++;
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
  ll ans = 1;
  ll index = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (s[y][x] == '#')
        continue;
      if (stop(y, x) == false && gridIndex[y][x] == 0) {
        ans = max(ans, bfs(y, x, ++index));
      }
    }
  }

  cout << ans << endl;
  return 0;
}