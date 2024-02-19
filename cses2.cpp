#include <iostream>
#define ll long long
using namespace std;
int cnt = 0;
string strStep;
bool visited[7][7];

bool empty(int y, int x) {
  return y >= 0 && y <= 6 && x >= 0 && x <= 6 && !visited[y][x];
}

void explorePath(int y, int x, int step = 0) {
  if ((!empty(y + 1, x) && !empty(y - 1, x)) && empty(y, x - 1) &&
      empty(y, x + 1))
    return;
  if ((!empty(y, x - 1) && !empty(y, x + 1)) && empty(y + 1, x) &&
      empty(y - 1, x))
    return;
  // 终结条件
  if (x == 0 && y == 6) {
    if (step == 48)
      cnt++;
    return;
  }

  visited[y][x] = true;

  if (strStep[step] == '?' || strStep[step] == 'U') {
    if (empty(y - 1, x)) {
      explorePath(y - 1, x, step + 1);
    }
  }
  if (strStep[step] == '?' || strStep[step] == 'D') {
    if (empty(y + 1, x)) {
      explorePath(y + 1, x, step + 1);
    }
  }

  if (strStep[step] == '?' || strStep[step] == 'L') {
    if (empty(y, x - 1)) {
      explorePath(y, x - 1, step + 1);
    }
  }
  if (strStep[step] == '?' || strStep[step] == 'R') {
    if (empty(y, x + 1)) {
      explorePath(y, x + 1, step + 1);
    }
  }

  visited[y][x] = false;
  return;
}

int main() {
  cin >> strStep;
  explorePath(0, 0);
  cout << cnt << endl;
  return 0;
}