/*
https://codeforces.com/problemset/problem/581/D
input
5 1 2 5 5 2
output
5
AAAAA
BBBBB
BBBBB
CCCCC
CCCCC
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int N = 0;
int ABCWidth[3];
int ABCLength[3];
vector<vector<char> > billboard;
string strABC = "ABC";
bool works(int bitmasks) {
  for (auto &row : billboard) fill(row.begin(), row.end(), 'E');

  for (size_t i = 0; i < strABC.size(); i++) {
    int width, length;
    switch (strABC[i]) {
      case 'A':
        width = ABCWidth[0];
        length = ABCLength[0];
        break;
      case 'B':
        width = ABCWidth[1];
        length = ABCLength[1];
        break;
      case 'C':
        width = ABCWidth[2];
        length = ABCLength[2];
        break;
    }

    int x = -1, y = -1;
    for (int xE = 0; xE < N; xE++) {
      for (int yE = 0; yE < N; yE++) {
        if (billboard[xE][yE] == 'E') {
          x = xE;
          y = yE;
          break;
        }
      }
      if (y != -1) {
        break;
      }
    }
    int X = (bitmasks & 1 << i) ? length : width;
    int Y = (bitmasks & 1 << i) ? width : length;

    for (int xLogo = 0; xLogo < X; xLogo++) {
      for (int yLogo = 0; yLogo < Y; yLogo++) {
        int newX = x + xLogo;
        int newY = y + yLogo;
        if (newX >= N || newY >= N || billboard[newX][newY] != 'E') {
          return false;
        }
        billboard[newX][newY] = strABC[i];
      }
    }
  }
  return true;
}

int main(void) {
  int totalarea = 0;
#include <cmath>  // Add this line to include the cmath library for the abs function

  const double EPSILON = 1e-9;  // Add this line to define a tolerance value

  for (int i = 0; i < 3; i++) {
    cin >> ABCLength[i] >> ABCWidth[i];
    totalarea += (ABCLength[i] * ABCWidth[i]);
  }

  if (abs(sqrt(totalarea) - floor(sqrt(totalarea))) <
      EPSILON) {  // Modify this line to compare the absolute difference to the
                  // tolerance
    N = static_cast<int>(floor(sqrt(totalarea)));
  } else {
    cout << "-1";
    return 0;
  }
  billboard.resize(N, vector<char>(N, 'E'));
  do {
    for (int bitmasks = 0; bitmasks < (1 << (strABC.size())); bitmasks++) {
      if (works(bitmasks)) {
        cout << N << '\n';
        for (int y = 0; y < N; y++) {
          for (int x = 0; x < N; x++) {
            cout << billboard[y][x];
            if (x == N - 1) cout << '\n';
          }
        }
        return 0;
      }
    }

  } while (next_permutation(strABC.begin(), strABC.end()));
  cout << "-1";
  return 0;
}