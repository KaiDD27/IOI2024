#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<ll>> grid, ansGrid;
vector<vector<pair<ll, ll>>> threePos = {
    {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}}};

bool fillOneZero(ll sum) {
  for (int i = 0; i < 8; i++) {
    ll zeroCnt = 0;
    ll tmpSum = 0;
    ll rFill = -1, cFill = -1;
    for (auto [r, c] : threePos[i]) {
      if (ansGrid[r][c] == 0) {
        zeroCnt++;
        rFill = r;
        cFill = c;
      }
      tmpSum += ansGrid[r][c];
    }
    if (zeroCnt == 1 && sum - tmpSum <= 10000 && sum - tmpSum > 0) {
      ansGrid[rFill][cFill] = sum - tmpSum;
      return true;
    }
  }
  return false;
}
bool checkValid(ll sum) {
  for (int i = 0; i < 8; i++) {
    ll tmpSum = 0;
    for (auto [r, c] : threePos[i]) {
      if (ansGrid[r][c] <= 0)
        return false;
      tmpSum += ansGrid[r][c];
    }
    if (tmpSum != sum)
      return false;
  }
  return true;
}

bool fillWithSum(ll sum) {
  while (true) {
    if (fillOneZero(sum) != true)
      break;
  }
  if (ansGrid[1][0] + ansGrid[1][1] + ansGrid[1][2] == sum &&
      ansGrid[0][1] + ansGrid[1][1] + ansGrid[2][1] == sum &&
      ansGrid[0][0] == 0 && ansGrid[0][2] == 0 && ansGrid[2][0] == 0 &&
      ansGrid[2][2] == 0) {
    ansGrid[0][0] = (sum - ansGrid[0][1] - ansGrid[1][0] + ansGrid[1][1]) / 2;
    while (true) {
      if (fillOneZero(sum) != true)
        break;
    }
  }
  if (checkValid(sum))
    return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  grid.resize(3, vector<ll>(3));
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      cin >> grid[r][c];
    }
  }
  ansGrid = grid;
  for (int i = 3; i <= 30000; i++) {
    ansGrid = grid;
    if (fillWithSum(i)) {
      break;
    }
  }
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      cout << ansGrid[r][c] << " ";
    }
    cout << endl;
  }
  return 0;
}