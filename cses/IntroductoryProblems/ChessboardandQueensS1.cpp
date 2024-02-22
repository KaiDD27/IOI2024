#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
bool chessboard[8][8];
bool diag1[15], diag2[15];
int ans = 0;
int pickX[8];

int main() {
  for (int y = 0; y < 8; y++) {
    string strTmp;
    cin >> strTmp;
    for (int x = 0; x < 8; x++) {
      chessboard[y][x] = (strTmp[x] == '.' ? false : true);
    }
  }
  iota(pickX, pickX + 8, 0);
  do {
    int ok = 1;
    fill(diag1, diag1 + 15, false);
    fill(diag2, diag2 + 15, false);
    for (int y = 0; y < 8; y++) {
      if (chessboard[y][pickX[y]] == true) {
        ok = 0;
        break;
      }

      if (diag1[y + pickX[y]] == true) {
        ok = 0;
        break;
      } else {
        diag1[y + pickX[y]] = true;
      }

      if (diag2[pickX[y] - y + 7] == true) {
        ok = 0;
        break;
      } else {
        diag2[pickX[y] - y + 7] = true;
      }
    }
    ans += ok;
  } while (next_permutation(pickX, pickX + 8));

  cout << ans << endl;
  return 0;
}