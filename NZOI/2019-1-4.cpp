#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

vector<tuple<int, int, int, int, char>> throws;
vector<vector<char>> compressGrid;
vector<int> ys, xs;
char chPColor;
int h, w, n;
ll calcPColor() {
  ll ans = 0;
  for (int yi = 0; yi < ys.size() - 1; yi++)
    for (int xi = 0; xi < xs.size() - 1; xi++) {
      if (compressGrid[yi][xi] == chPColor) {
        long long r = ys[yi + 1] - ys[yi];
        long long c = xs[xi + 1] - xs[xi];
        ans += r * c;
      }
    }
  return ans;
}
int findCompressX(int ox) {
  return find(xs.begin(), xs.end(), ox) - xs.begin();
}
int findCompressY(int oy) {
  return find(ys.begin(), ys.end(), oy) - ys.begin();
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> h >> w >> n;
  throws.resize(n);
  ys = {0, h};
  xs = {0, w};
  for (auto &[leftUpX, leftUpY, rightDownX, rightDownY, color] : throws) {
    int x, y, spread;
    char chColor;
    cin >> x >> y >> spread >> chColor;
    leftUpX = max(0, x - spread);
    leftUpY = max(0, y - spread);
    rightDownX = min(w, x + spread + 1);
    rightDownY = min(h, y + spread + 1);
    color = chColor;
    xs.push_back(leftUpX);
    ys.push_back(leftUpY);
    xs.push_back(rightDownX);
    ys.push_back(rightDownY);
  }
  cin >> chPColor;
  sort(ys.begin(), ys.end());
  sort(xs.begin(), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  compressGrid.resize(ys.size(), vector<char>(xs.size(), ' '));
  bool flagStart = false;
  for (auto [leftUpX, leftUpY, rightDownX, rightDownY, color] : throws) {
    if (color == chPColor || flagStart == true) {
      for (int yi = findCompressY(leftUpY); yi < findCompressY(rightDownY);
           yi++) {
        for (int xi = findCompressX(leftUpX); xi < findCompressX(rightDownX);
             xi++) {
          compressGrid[yi][xi] = color;
        }
      }
      flagStart = true;
    }
  }
  cout << calcPColor() << endl;
  return 0;
}
