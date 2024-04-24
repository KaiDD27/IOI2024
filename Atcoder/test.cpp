#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, t, fx, fy, sx, sy, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0},
                             a[205][205], b[205][205], dis[205][205];
struct node {
  int x, y, val;
  const bool operator<(const node &x) const { return val < x.val; }
};

void bfs() {
  priority_queue<node> q; // 使用优先队列将剩余能量较大的排在前面进行优化
  memset(dis, -0x3f, sizeof dis);  // 初始化
  dis[sx][sy] = max(b[sx][sy], 0); // 初始化
  q.push({sx, sy, dis[sx][sy]});   // 起点入队
  while (q.size()) {
    auto [x, y, val] = q.top(); // 出队
    q.pop();
    if (x == fx && y == fy) {
      cout << "Yes" << endl; // 如果走到终点就结束
      return;
    }
    if (!val)
      continue; // 如果没能量了就舍去
    if (val < dis[x][y])
      continue; // 如果走到的格子记录的能量比现在的大就舍去
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > m || !a[xx][yy])
        continue; // 判出图以及障碍
      int v = b[xx][yy] ? max(b[xx][yy], val - 1) : val - 1; // 是否喝药
      if (v > dis[xx][yy]) {
        // 剩余能量比当前格子记录的大，更新记录的能量并入队
        q.push({xx, yy, v});
        dis[xx][yy] = v;
      }
    }
  }
  cout << "No" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      // 标记地图
      a[i][j] = 1;
      if (c == 'S')
        sx = i, sy = j;
      if (c == 'T')
        fx = i, fy = j;
      if (c == '#')
        a[i][j] = 0;
    }
  }
  cin >> t;
  // 标记药水
  for (int x, y, z; t--;) {
    cin >> x >> y >> z;
    b[x][y] = z;
  }
  bfs();
  return 0;
}