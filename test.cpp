#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

// 定义一个结构体来表示每次的涂色操作
struct rect {
  int x, y, u, v; // 涂色区域的左上角(x, y)和右下角(u, v)的坐标
  char colour;    // 涂色的颜色
};

vector<int> row, col; // 用于存储行和列的分割点

// 返回值在row数组中的位置
int r(int val) {
  return lower_bound(row.begin(), row.end(), val) - row.begin();
}

// 返回值在col数组中的位置
int c(int val) {
  return lower_bound(col.begin(), col.end(), val) - col.begin();
}

char canvas[100][100]; // 用于存储画布的颜色

int main() {
  int height, width, n_throws;
  cin >> height >> width >> n_throws;

  row = {0, height}; // 初始化行分割点
  col = {0, width};  // 初始化列分割点

  vector<rect> to_process; // 用于存储所有的涂色操作

  for (int i = 0; i < n_throws; ++i) {
    int zx, zy, spread;
    cin >> zx >> zy >> spread;
    char colour;
    cin >> colour;

    // 计算涂色区域的边界
    int x = max(0, zx - spread);
    int y = max(0, zy - spread);
    int u = min(width, zx + spread + 1);
    int v = min(height, zy + spread + 1);

    to_process.push_back({x, y, u, v, colour}); // 将涂色操作加入待处理列表
    col.push_back(x);                           // 将边界加入列分割点
    col.push_back(u);
    row.push_back(y); // 将边界加入行分割点
    row.push_back(v);
  }

  // 对行和列分割点进行排序并去重
  sort(row.begin(), row.end());
  sort(col.begin(), col.end());
  row.erase(unique(row.begin(), row.end()), row.end());
  col.erase(unique(col.begin(), col.end()), col.end());

  // 处理每一个涂色操作
  for (rect p : to_process) {
    for (int i = r(p.y); i < r(p.v); i++) {
      for (int j = c(p.x); j < c(p.u); j++) {
        canvas[i][j] = p.colour; // 涂色
      }
    }
  }

  char colour;
  cin >> colour; // 读取要查询的颜色
  long long res = 0;

  // 计算指定颜色的面积
  for (size_t i = 0; i < row.size() - 1; i++) {
    for (size_t j = 0; j < col.size() - 1; j++) {
      if (canvas[i][j] == colour) {
        long long r = row[i + 1] - row[i];
        long long c = col[j + 1] - col[j];
        res += r * c; // 计算面积并累加
      }
    }
  }

  cout << res; // 输出结果
  return 0;
}