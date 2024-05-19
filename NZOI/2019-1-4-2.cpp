#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

// 定义一个结构体来表示矩形
struct Rectangle {
  int x1, y1, x2, y2;
  char color;

  Rectangle(int _x1, int _y1, int _x2, int _y2, char _color)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2), color(_color) {}
};

// 检查两个矩形是否相交
bool intersects(const Rectangle &r1, const Rectangle &r2) {
  return !(r1.x2 <= r2.x1 || r1.x1 >= r2.x2 || r1.y2 <= r2.y1 ||
           r1.y1 >= r2.y2);
}

// 分割矩形
vector<Rectangle> splitRectangle(const Rectangle &r1, const Rectangle &r2) {
  vector<Rectangle> result;

  // 上方区域
  if (r1.y1 < r2.y1) {
    result.emplace_back(r1.x1, r1.y1, r1.x2, r2.y1, r1.color);
  }
  // 下方区域
  if (r1.y2 > r2.y2) {
    result.emplace_back(r1.x1, r2.y2, r1.x2, r1.y2, r1.color);
  }
  // 左方区域
  if (r1.x1 < r2.x1) {
    result.emplace_back(r1.x1, max(r1.y1, r2.y1), r2.x1, min(r1.y2, r2.y2),
                        r1.color);
  }
  // 右方区域
  if (r1.x2 > r2.x2) {
    result.emplace_back(r2.x2, max(r1.y1, r2.y1), r1.x2, min(r1.y2, r2.y2),
                        r1.color);
  }

  return result;
}

int main() {
  int height, width, n_throws;
  cin >> height >> width >> n_throws;

  vector<Rectangle> rectangles;
  queue<tuple<int, int, int, int, char>> events;

  // 读取涂色操作并存入事件队列
  for (int i = 0; i < n_throws; ++i) {
    int x, y, spread;
    char color;
    cin >> x >> y >> spread >> color;
    int x1 = max(0, x - spread);
    int y1 = max(0, y - spread);
    int x2 = min(width, x + spread + 1);
    int y2 = min(height, y + spread + 1);
    events.emplace(x1, y1, x2, y2, color);
  }

  char query_color;
  cin >> query_color;

  // 处理每个事件
  while (!events.empty()) {
    auto [x1, y1, x2, y2, color] = events.front();
    events.pop();
    Rectangle new_rect(x1, y1, x2, y2, color);

    vector<Rectangle> new_rectangles;
    for (const auto &rect : rectangles) {
      if (intersects(rect, new_rect)) {
        auto split_rects = splitRectangle(rect, new_rect);
        new_rectangles.insert(new_rectangles.end(), split_rects.begin(),
                              split_rects.end());
      } else {
        new_rectangles.push_back(rect);
      }
    }
    new_rectangles.push_back(new_rect);
    rectangles = move(new_rectangles);
  }

  // 计算指定颜色的面积
  long long area = 0;
  for (const auto &rect : rectangles) {
    if (rect.color == query_color) {
      long long c = rect.x2 - rect.x1;
      long long r = rect.y2 - rect.y1;
      area += c * r;
    }
  }

  cout << area << endl;
  return 0;
}
