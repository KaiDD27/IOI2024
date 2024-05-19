#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

struct rect {
  int leftUpX, leftUpY, rightDownX, rightDownY;
  char chColor; //
};
vector<rect> throws;
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
  return lower_bound(xs.begin(), xs.end(), ox) - xs.begin();
}
int findCompressY(int oy) {
  return lower_bound(ys.begin(), ys.end(), oy) - ys.begin();
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> h >> w >> n;
  throws.resize(n);
  ys = {0, h};
  xs = {0, w};
  for (int i = 0; i < n; i++) {
    int x, y, spread;
    char chColor;
    cin >> x >> y >> spread >> chColor;
    throws[i].leftUpX = max(0, x - spread);
    throws[i].leftUpY = max(0, y - spread);
    throws[i].rightDownX = min(w, x + spread + 1);
    throws[i].rightDownY = min(h, y + spread + 1);
    throws[i].chColor = chColor;
    xs.push_back(throws[i].leftUpX);
    ys.push_back(throws[i].leftUpY);
    xs.push_back(throws[i].rightDownX);
    ys.push_back(throws[i].rightDownY);
  }
  cin >> chPColor;
  sort(ys.begin(), ys.end());
  sort(xs.begin(), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  compressGrid.resize(ys.size(), vector<char>(xs.size(), ' '));
  bool flagStart = false;
  for (int i = 0; i < n; i++) {
    if (throws[i].chColor == chPColor || flagStart == true) {
      for (int yi = findCompressY(throws[i].leftUpY);
           yi < findCompressY(throws[i].rightDownY); yi++) {
        for (int xi = findCompressX(throws[i].leftUpX);
             xi < findCompressX(throws[i].rightDownX); xi++) {
          compressGrid[yi][xi] = throws[i].chColor;
        }
      }
      flagStart = true;
    }
  }
  cout << calcPColor() << endl;
  return 0;
}
