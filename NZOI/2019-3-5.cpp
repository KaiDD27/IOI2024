#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int> skills;
vector<vector<int>> strongerCnt;
int simulate(int p, int i, int j) {
  int wins = 0;
  for (int r = 1; r <= k; r++) {
    // 属于同一个区的比Toddy 强的选手数量
    int currStrongerCnt = strongerCnt[r][p >> r];
    // 交换最多只能减少一个强手，所以如果大于 1，则一定没法赢了
    if (currStrongerCnt > 1)
      break;
    // Adjust to account for swap of players i and j
    if (p >> r == i >> r) {
      // Player i within sub-bracket
      currStrongerCnt += strongerCnt[0][j] - strongerCnt[0][i];
    }
    if (p >> r == j >> r) {
      // Player j within sub-bracket
      currStrongerCnt += strongerCnt[0][i] - strongerCnt[0][j];
    }
    if (currStrongerCnt == 0) {
      wins++;
    } else {
      break;
    }
  }
  return wins;
}

int main() {
  cin >> n >> k;
  skills.resize(n);
  strongerCnt.resize(k + 1, vector<int>(n));
  for (int i = 0; i < n; i++)
    cin >> skills[i];

  int firstLoss = 0;
  int maxWins = 0;
  int ways = 0;
  // 遍历，第一个比
  // Toddy强的，不一定是会遇上Toddy，如果遇不上，那么将和别人交换就无益处，一定有人在这个区赢
  // Toddy，对结果没影响，所以不需要找出第一个真正赢了 Toddy 的人。
  for (int i = 1; i < n; i++) {
    skills[i] = skills[i] > skills[0];
    if (skills[i] && !firstLoss)
      firstLoss = i;
    strongerCnt[0][i] = skills[i];
  }
  skills[0] = 0;
  strongerCnt[0][0] = 0;

  for (int r = 1; r <= k; r++) {
    for (int m = 0; m < (n >> r); m++) {
      strongerCnt[r][m] =
          strongerCnt[r - 1][m * 2] + strongerCnt[r - 1][m * 2 + 1];
    }
  }

  int initialWins = simulate(0, 0, 0);
  for (int i = 0; i < n; i++) {
    // Try swapping Toddy with player i
    int wins = simulate(i, 0, i);
    if (wins > maxWins) {
      maxWins = wins;
      ways = 1;
    } else if (wins != 0 && wins == maxWins) {
      ways++;
    }

    // Try swapping the first player Toddy loses to with player i
    if (firstLoss) {
      wins = simulate(0, firstLoss, i);
      if (wins > maxWins) {
        maxWins = wins;
        ways = 1;
      } else if (wins == maxWins) {
        ways++;
      }
    }
  }

  if (initialWins == maxWins)
    ways = -1;
  cout << maxWins << endl << ways << endl;
}