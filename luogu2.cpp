#include <iostream>
using namespace std;
int gird[45][45];
int main() {
  int N;
  cin >> N;
  gird[1][N / 2 + 1] = 1;
  int line = 1, column = N / 2 + 1;
  for (int K = 2; K <= N * N; K++) {
    if (line == 1 && column != N) {
      line = N, column += 1;

    } else if (line != 1 && column == N) {
      line -= 1, column = 1;

    } else if (line == 1 && column == N) {
      line += 1;

    } else if (line != 1 && column != N) {
      if (gird[line - 1][column + 1] == 0) {
        line -= 1;
        column += 1;
      } else {
        line += 1;
      }
    }
    gird[line][column] = K;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << gird[i][j] << " ";
    cout << endl;
  }
}