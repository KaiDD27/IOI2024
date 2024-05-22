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
int ways[17];

int main() {
  cin >> n >> k;
  int notStronger = 0;
  int initialWins = 0;
  skills.resize(n);
  strongerCnt.resize(k + 1, vector<int>(n));
  for (int i = 0; i < n; i++) {
    cin >> skills[i];
    strongerCnt[0][i] = skills[i] > skills[0];
    notStronger += !strongerCnt[0][i];
  }

  for (int r = 1; r <= k; r++) {
    for (int m = 0; m < (n >> r); m++) {
      strongerCnt[r][m] =
          strongerCnt[r - 1][m * 2] + strongerCnt[r - 1][m * 2 + 1];
    }
  }
  // way 数组的下标代表赢r 次有几种交换方式
  for (int r = 1; r <= k; r++) {
    for (int m = 0; m < (n >> r); m++) {
      if (m == 0 && strongerCnt[r][m] == 0) {
        initialWins++;
        break;
      }
      if (m == 0 && strongerCnt[r][m] == 1)
        // 当前区有 2 的r 次方个选手，其中只有一个高手，所以
        // 所有的非高手减去当前区的非高手，就是剩下可以和这个高手交换的人选了
        ways[r] += notStronger - ((1 << r) - 1);
      else if (m != 0 && strongerCnt[r][m] == 0)
        // 和当前区所有的非高手交换都可以。
        ways[r] += (1 << r);
      else if (m != 0 && strongerCnt[r][m] == 1)
        // 和当前区的唯一的一个高手交换可以
        ways[r]++;
    }
    if (initialWins != r && ways[r] == 0)
      break;
  }

  int maxWins = initialWins;
  for (int wins = 1; wins <= k; wins++) {
    if (ways[wins])
      maxWins = max(maxWins, wins);
  }

  if (initialWins == maxWins)
    ways[maxWins] = -1;
  cout << maxWins << endl << ways[maxWins] << endl;
}