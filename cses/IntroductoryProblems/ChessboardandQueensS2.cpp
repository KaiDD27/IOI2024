#include <iostream>

using namespace std;
bool chessboard[8][8];
bool col[8], diag1[15], diag2[15];
int ans = 0;
void search(int y) {
  if (y == 8) {
    ans++;
    return;
  }
  for (int x = 0; x < 8; x++) {
    if (col[x] == true || diag1[x + y] == true || diag2[x - y + 7] == true ||
        chessboard[y][x] == true)
      continue;
    col[x] = true;
    diag1[x + y] = true;
    diag2[x - y + 7] = true;
    search(y + 1);
    col[x] = false;
    diag1[x + y] = false;
    diag2[x - y + 7] = false;
  }
}

int main() {
  for (int y = 0; y < 8; y++) {
    string strTmp;
    cin >> strTmp;
    for (int x = 0; x < 8; x++) {
      chessboard[y][x] = (strTmp[x] == '.' ? false : true);
    }
  }
  search(0);
  cout << ans << endl;
  return 0;
}