#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int steps[9][9] = {0};

// 计算(x, y)位置的下一个可能移动的数量
int possibleCnt(int x, int y) {
  if (x < 1 || x > 8 || y < 1 || y > 8 || steps[y][x] != 0)
    return 9;
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > 8 || ny < 1 || ny > 8 || steps[ny][nx] != 0)
      continue;
    cnt++;
  }
  return cnt;
}
// 使用warnsdorff规则进行骑士巡游
bool warnsdorf(int x, int y, int cnt) {
  steps[y][x] = cnt;
  if (cnt >= 64)
    return true;
  // 使用优先队列（最小堆）来存储下一个可能的移动和它们的可能性
  priority_queue<array<int, 3>> pq;
  int smallest = 9;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    int nextMoves = possibleCnt(nx, ny);
    if (nextMoves <= 8) {
      pq.push({-nextMoves, nx, ny});
    }
  }
  while (!pq.empty()) {
    int nx = pq.top()[1], ny = pq.top()[2];
    pq.pop();
    if (warnsdorf(nx, ny, cnt + 1) == true)
      return true;
    steps[ny][nx] = 0; // 回溯
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int x, y;
  cin >> x >> y;
  warnsdorf(x, y, 1);
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cout << steps[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}