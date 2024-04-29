#include <array>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string dir = "URDL";
vector<int> moveDir;
// 0:走了几步了初始是 0 步；1：x 2：y
vector<array<int, 3>> partCurrPosition;
vector<pair<int, int>> headXY;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, q;
  cin >> n >> q;
  for (int i = n; i > 0; i++) {
    headXY.push_back({n, 0});
  }

  partCurrPosition.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    partCurrPosition[i][0] = 0;
    partCurrPosition[i][1] = i;
    partCurrPosition[i][2] = 0;
  }
  for (int i = 0; i < q; i++) {
    int type;
    int part;
    char direction;
    cin >> type;
    if (type == 1) {
      cin >> direction;
      for (int j = 0; j < 4; j++) {
        if (direction == dir[j]) {
          int x, y;

          break;
        }
      }
      continue;
    }

    if (type == 2) {
      cin >> part;
      int x, y;
      x = partCurrPosition[part][1];
      y = partCurrPosition[part][2];
      for (int j = partCurrPosition[part][0]; j < moveDir.size(); j++) {
        x += dx[moveDir[j]];
        y += dy[moveDir[j]];
      }
      partCurrPosition[part][0] = moveDir.size();
      partCurrPosition[part][1] = x;
      partCurrPosition[part][2] = y;
      cout << x << " " << y << endl;
    }
  }
  return 0;
}
