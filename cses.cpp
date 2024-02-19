#include <iostream>
using namespace std;

const int PATH_LEN = 48; // length of all possible paths
const int GRID_SIZE = 7;
bool visited[GRID_SIZE][GRID_SIZE];

int cnt = 0;
string strStep;

int empty(int y, int x) {
  return y >= 0 && y <= GRID_SIZE - 1 && x >= 0 && x <= GRID_SIZE - 1 &&
         !visited[y][x];
}

bool DeadEnd(int y, int x) {
  if (!(x == 0 && y == GRID_SIZE - 1) &&
      empty(y + 1, x) + empty(y - 1, x) + empty(y, x + 1) + empty(y, x - 1) ==
          1)
    return true;
  return false;
}

void explorePath(int y, int x, int step = 0) {
  // 终结条件
  if (x == 0 && y == GRID_SIZE - 1) {
    if (step == PATH_LEN)
      cnt++;
    return;
  }

  visited[y][x] = true;

  char charStep = 'N';
  if (charStep == 'N' && empty(y - 1, x)) {
    if (DeadEnd(y - 1, x))
      charStep = 'U';
  }
  if (charStep == 'N' && empty(y + 1, x)) {
    if (DeadEnd(y + 1, x))
      charStep = 'D';
  }
  if (charStep == 'N' && empty(y, x - 1)) {
    if (DeadEnd(y, x - 1))
      charStep = 'L';
  }
  if (charStep == 'N' && empty(y, x + 1)) {
    if (DeadEnd(y, x + 1))
      charStep = 'R';
  }
  if (charStep == 'N')
    charStep = strStep[step];
  else if (strStep[step] != '?' && charStep != strStep[step]) {
    visited[y][x] = false;
    return;
  }

  if (charStep == '?' || charStep == 'U') {
    if (empty(y - 1, x)) {
      if (!(!empty(y - 2, x) && empty(y - 1, x - 1) && empty(y - 1, x + 1))) {
        explorePath(y - 1, x, step + 1);
      }
    }
  }
  if (charStep == '?' || charStep == 'D') {
    if (empty(y + 1, x)) {
      if (!(!empty(y + 2, x) && empty(y + 1, x - 1) && empty(y + 1, x + 1))) {
        explorePath(y + 1, x, step + 1);
      }
    }
  }
  if (charStep == '?' || charStep == 'L') {
    if (empty(y, x - 1)) {
      if (!(!empty(y, x - 2) && empty(y - 1, x - 1) && empty(y + 1, x - 1))) {
        explorePath(y, x - 1, step + 1);
      }
    }
  }
  if (charStep == '?' || charStep == 'R') {
    if (empty(y, x + 1)) {
      if (!(!empty(y, x + 2) && empty(y - 1, x + 1) && empty(y + 1, x + 1))) {
        explorePath(y, x + 1, step + 1);
      }
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