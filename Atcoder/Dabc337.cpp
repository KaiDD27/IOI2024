#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> grid;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll h, w, k;
  cin >> h >> w >> k;
  grid.resize(h + 2);
  for (int i = 1; i <= h; i++) {
    string strTemp;
    cin >> strTemp;
    grid[i] = "x" + strTemp + "x";
  }
  string strWall;
  for (int i = 0; i <= w + 1; i++)
    strWall.push_back('x');
  grid[0] = strWall;
  grid[h + 1] = strWall;
  vector<array<int, 3>> preSumW(w + 1);
  vector<array<int, 3>> preSumH(h + 1);
  int opCnt = k + 1;
  if (k <= w) {
    for (int y = 1; y <= h; y++) {
      preSumW.clear();
      preSumW.resize(w + 1);
      for (int x = 1; x <= w; x++) {
        preSumW[x] = preSumW[x - 1];
        switch (grid[y][x]) {
        case 'o':
          preSumW[x][0]++;
          break;
        case 'x':
          preSumW[x][1]++;
          break;
        case '.':
          preSumW[x][2]++;
          break;
        }
      }
      for (int x = k; x <= w; x++) {
        if (preSumW[x][1] - preSumW[x - k][1] != 0)
          continue;
        opCnt = min(opCnt, preSumW[x][2] - preSumW[x - k][2]);
      }
    }
  }
  if (k <= h) {
    for (int x = 1; x <= w; x++) {
      preSumH.clear();
      preSumH.resize(h + 1);
      for (int y = 1; y <= h; y++) {
        preSumH[y] = preSumH[y - 1];
        switch (grid[y][x]) {
        case 'o':
          preSumH[y][0]++;
          break;
        case 'x':
          preSumH[y][1]++;
          break;
        case '.':
          preSumH[y][2]++;
          break;
        }
      }
      for (int y = k; y <= h; y++) {
        if (preSumH[y][1] - preSumH[y - k][1] != 0)
          continue;
        opCnt = min(opCnt, preSumH[y][2] - preSumH[y - k][2]);
      }
    }
  }
  if (opCnt > k)
    cout << -1 << endl;
  else
    cout << opCnt << endl;
  return 0;
}