#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define LL long long
#define ULL unsigned long long

const LL mod_1 = 1e9 + 7;
const LL mod_2 = 998244353;

const double eps_1 = 1e-5;
const double eps_2 = 1e-10;

const int maxn = 2e2 + 10;

bool stop[maxn][maxn];

int maxE[maxn][maxn];

int med[maxn][maxn];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int row, col, tx, ty;

bool use[maxn][maxn];
int qx[maxn * maxn], qy[maxn * maxn], step[maxn][maxn];
bool judge[maxn][maxn];

priority_queue<array<int, 3>> que;

/// siz=row*col O(siz*E) = 1600000000
/// 有没有方法证明这个方法复杂度会低一点/很多？
/// AC 49 ; TLE 4

void dfs(int x, int y) {
  int i, xx, yy;
  ///======

  /**
  1. 还是4TLE
  2. 先往终点/step[x][y]小的方向走？
  3. 按照E的能量排序走？
  4. 优先队列？
  **/

  if (x == tx && y == ty) {
    cout << "Yes" << endl;
    exit(0);
  }
  if (maxE[x][y] >= step[x][y]) {
    cout << "Yes" << endl;
    exit(0);
  }

  ///======

  for (i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];

    if (xx >= 0 && xx < row && yy >= 0 && yy < col && stop[xx][yy] == 0 &&
        maxE[x][y] - 1 > maxE[xx][yy]) {
      maxE[xx][yy] = max(maxE[x][y] - 1, med[xx][yy]);
      dfs(xx, yy);
    }
  }
}

int main() {
  int i, j;
  int q, sx, sy, x, y, e;
  char ch;
  int head, tail, xx, yy;
  memset(stop, 0, sizeof(stop));
  scanf("%d%d%c", &row, &col, &ch);
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%c", &ch);
      if (ch == '#')
        stop[i][j] = 1;
      else if (ch == 'S')
        sx = i, sy = j;
      else if (ch == 'T')
        tx = i, ty = j;
    }
    scanf("%c", &ch);
  }

  memset(med, 0, sizeof(med));
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &x, &y, &e);
    x--, y--;
    med[x][y] = e;
  }

  memset(use, 0, sizeof(use));
  memset(step, 127, sizeof(step));
  head = 0, tail = 1;
  qx[1] = tx, qy[1] = ty, use[tx][ty] = 1, step[tx][ty] = 0;
  while (head < tail) {
    head++;
    x = qx[head], y = qy[head];

    for (i = 0; i < 4; i++) {
      xx = x + dx[i];
      yy = y + dy[i];

      if (xx >= 0 && xx < row && yy >= 0 && yy < col && stop[xx][yy] == 0 &&
          !use[xx][yy]) {
        tail++;
        qx[tail] = xx, qy[tail] = yy, use[xx][yy] = 1,
        step[xx][yy] = step[x][y] + 1;
      }
    }
  }
  /*
  for (i=0;i<row;i++)
  {
      for (j=0;j<col;j++)
          printf("%d ",step[i][j]);
      printf("\n");
  }
  */

  memset(maxE, 0xff, sizeof(maxE));
  maxE[sx][sy] = med[sx][sy];
  memset(judge, 0, sizeof(judge));
  // dfs(sx,sy);

  ///*
  que.push({med[sx][sy], sx, sy});
  while (!que.empty()) {
    auto temp = que.top();
    que.pop();
    e = temp[0], x = temp[1], y = temp[2];
    if (maxE[x][y] > e)
      continue;

    // maxE[x][y]=e;
    /// judge[x][y]=1;
    // cout<<"test "<<e<<" "<<x<<" "<<y<<endl;

    if (x == tx && y == ty) {
      cout << "Yes" << endl;
      exit(0);
    }
    if (maxE[x][y] >= step[x][y]) {
      cout << "Yes" << endl;
      exit(0);
    }

    for (i = 0; i < 4; i++) {
      xx = x + dx[i];
      yy = y + dy[i];

      if (xx >= 0 && xx < row && yy >= 0 && yy < col && stop[xx][yy] == 0 &&
          e - 1 > maxE[xx][yy]) /// && !judge[xx][yy]
      {
        // maxE[xx][yy]=e-1;
        maxE[xx][yy] = max(e - 1, med[xx][yy]);
        que.push({maxE[xx][yy], xx, yy});
      }
    }
  }
  //*/

  /// 药物只能吃一次：其实最多只需要吃一次。这个条件就可以去掉

  cout << "No" << endl;

  return 0;
}
/*
6 6
...#.#
....S#
......
####.#
####.#
####T#
1
2 5 4

======

6 6
...#.#
....S#
......
####.#
####.#
####T#
1
2 5 3

======

6 6
...#.#
....S#
....#.
####.#
####.#
####T#
1
2 5 4

======


*/