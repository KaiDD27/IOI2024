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
vector<pair<int, int>> headXY;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, q;
  cin >> n >> q;
  for (int i = n; i > 0; i--) {
    headXY.push_back({i, 0});
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
          int x = headXY.back().first;
          int y = headXY.back().second;
          x += dx[j];
          y += dy[j];
          headXY.push_back({x, y});
          break;
        }
      }
      continue;
    }

    if (type == 2) {
      cin >> part;
      cout << headXY[headXY.size() - part].first << " "
           << headXY[headXY.size() - part].second << endl;
    }
  }
  return 0;
}
