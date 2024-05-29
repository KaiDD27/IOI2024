// 将问题转化为相邻的两个数字之间的关系的小问题来解决
#include <array>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int r, c;
vector<vector<int>> grid;
set<int> unusedCols; // 未确定排序顺序/优先级的列
vector<int> tiedRows;
vector<int> ascCounts;
vector<int> descCounts;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  // 读取输入
  cin >> r >> c;
  grid.resize(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  unusedCols.clear();
  for (int i = 0; i < c; i++) {
    unusedCols.insert(i);
  }

  tiedRows.clear();
  for (int i = 0; i < r - 1; i++) {
    tiedRows.push_back(i);
  }

  ascCounts.resize(c);
  descCounts.resize(c);

  // 初始化每行的升序/降序计数
  for (int ri = 0; ri < r - 1; ri++) {
    for (int ci = 0; ci < c; ci++) {
      if (grid[ri + 1][ci] > grid[ri][ci])
        ascCounts[ci]++;
      if (grid[ri + 1][ci] < grid[ri][ci])
        descCounts[ci]++;
    }
  }

  while (!unusedCols.empty()) {
    int col = -1;
    // 找到一个可以作为下一个键的列
    // 一边计算一边输出，容易导致超时，可以考虑先存在一个 vectorstring
    // 数组里面，最后统一输出
    for (int ci : unusedCols) {
      if (descCounts[ci] == 0) { // 没有降序对，所以列必须是升序的
        cout << ci + 1 << " asc" << endl;
        col = ci;
        break;
      }
      if (ascCounts[ci] == 0) { // 没有升序对，所以列必须是降序的
        cout << ci + 1 << " desc" << endl;
        col = ci;
        break;
      }
    }
    // 因为保证有解所以必须能找到一个 col
    unusedCols.erase(col);
    vector<int> nextRows;
    for (int ri : tiedRows) {
      // 如果仍然是相同的一对，将其添加到下一次迭代中必须检查的行中
      if (grid[ri + 1][col] == grid[ri][col]) {
        nextRows.push_back(ri);
      } else {
        // 因为不是相同的对，所以需要从下次迭代检查中去掉
        for (int ci : unusedCols) {
          if (grid[ri + 1][ci] > grid[ri][ci])
            ascCounts[ci]--; // 对是降序的，所以减少列的升序计数
          if (grid[ri + 1][ci] < grid[ri][ci])
            descCounts[ci]--; // 对是升序的，所以减少列的降序计数
        }
      }
    }
    tiedRows = nextRows;
  }
}