// 将问题转化为相邻的两个数字之间的关系的小问题来解决
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int r, c;
int grid[2010][2010];
set<int> stUnusedCols; // 未确定排序顺序/优先级的列
vector<pair<int, int>> tieRowsIntervals;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  // 读取输入
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < c; i++) {
    stUnusedCols.insert(i);
  }
  // 左闭右开
  tieRowsIntervals.push_back({0, r});
  while (!stUnusedCols.empty()) {
    int col = -1;
    // 找到一个可以作为下一个键的列
    // 一边计算一边输出，容易导致超时，可以考虑先存在一个 vectorstring
    // 数组里面，最后统一输出
    for (int ci : stUnusedCols) {
      int flagAscOrDescOrNo = 1;
      bool flagFirst = true;
      for (auto [rowBegin, rowEnd] : tieRowsIntervals) {
        for (int i = rowBegin + 1; i < rowEnd; i++) {
          if (flagFirst == true) {
            if (grid[i][ci] == grid[i - 1][ci])
              continue;
            if (grid[i][ci] < grid[i - 1][ci])
              flagAscOrDescOrNo = 2;
            if (grid[i][ci] > grid[i - 1][ci])
              flagAscOrDescOrNo = 1;
            flagFirst = false;
          } else {
            if (grid[i][ci] < grid[i - 1][ci] && flagAscOrDescOrNo == 1) {
              flagAscOrDescOrNo = 0;
              break;
            }
            if (grid[i][ci] > grid[i - 1][ci] && flagAscOrDescOrNo == 2) {
              flagAscOrDescOrNo = 0;
              break;
            }
          }
        }
        if (flagAscOrDescOrNo == 0)
          break;
      }
      if (flagAscOrDescOrNo == 1) {
        cout << ci + 1 << " asc" << endl;
        col = ci;
        break;
      }
      if (flagAscOrDescOrNo == 2) {
        cout << ci + 1 << " desc" << endl;
        col = ci;
        break;
      }
    }

    // 因为保证有解所以必须能找到一个 col
    stUnusedCols.erase(col);
    vector<pair<int, int>> newTieRowsIntervals;
    for (auto [rowBegin, rowEnd] : tieRowsIntervals) {
      for (int i = rowBegin + 1, ni = rowBegin, ne = rowBegin + 1; i < rowEnd;
           i++) {
        if (grid[i][col] == grid[i - 1][col]) {
          ne++;
          if (ne == rowEnd) {
            newTieRowsIntervals.push_back({ni, ne});
          }
        } else {
          if (ne - ni > 1) {
            newTieRowsIntervals.push_back({ni, ne});
          }
          ni = ne;
          ne++;
        }
      }
    }
    tieRowsIntervals = newTieRowsIntervals;
  }
}