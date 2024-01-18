#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
vector<vector<int>> ans;
vector<int> UP = {-1, 0}, DOWN = {1, 0}, LEFT = {0, -1}, RIGHT = {0, 1};
vector<vector<int>> clockwise = {UP, RIGHT, DOWN, LEFT},
                    counterClockwise = {UP, LEFT, DOWN, RIGHT};
void spirale(int y, int x, bool boolCounter) {
  vector<vector<int>> dirs = boolCounter ? counterClockwise : clockwise;
  int cnt = 0, d_idx = 0, length = 1, remain = 1, step = 1;
  bool shd_increase = false;
  while (cnt < N * M) {
    bool out = y < 0 || x < 0 || y > N - 1 || x > M - 1;
    if (!out) {
      ans[y][x] = min(ans[y][x], step);
      cnt++;
    }
    step++;
    y += dirs[d_idx][0];
    x += dirs[d_idx][1];
    remain--;
    if (remain == 0) {
      if (shd_increase)
        length++;
      d_idx = (d_idx + 1) % 4;
      remain = length;
      shd_increase = !shd_increase;
    }
  }
}

int main() {
  cin >> N >> M >> K;
  ans = vector<vector<int>>(N, vector<int>(M, INT32_MAX));
  for (int i = 0; i < K; i++) {
    int y, x, t;
    cin >> y >> x >> t;
    spirale(y - 1, x - 1, t);
  }
  for (const auto &row : ans) {
    for (int v : row) {
      cout << v << " ";
    }
    cout << endl;
  }
}