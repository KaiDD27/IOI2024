#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int> skills;
vector<int> strongerCnt;
int ways[17];

int main() {
  cin >> n >> k;
  int notStronger = 0;
  int initialWins = 0;
  skills.resize(n);
  strongerCnt.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> skills[i];
    strongerCnt[i] = skills[i] > skills[0];
    notStronger += !strongerCnt[i];
  }
  // way 数组的下标代表赢r 次有几种交换方式
  for (int r = 1; r <= k; r++) {
    for (int m = 0; m < (n >> r); m++) {
      // 滚动数组优化
      strongerCnt[m] = strongerCnt[m * 2] + strongerCnt[m * 2 + 1];
      if (m == 0 && strongerCnt[m] == 0) {
        initialWins++;
        continue;
      }
      if (m == 0 && strongerCnt[m] == 1)
        // 当前区有 2 的r 次方个选手，其中只有一个高手，所以
        // 所有的非高手减去当前区的非高手，就是剩下可以和这个高手交换的人选了
        ways[r] += notStronger - ((1 << r) - 1);
      if (m != 0 && strongerCnt[m] == 0)
        // 和当前区所有的非高手交换都可以。
        ways[r] += (1 << r);
      if (m != 0 && strongerCnt[m] == 1)
        // 和当前区的唯一的一个高手交换可以
        ways[r]++;
    }
  }

  int maxWins = initialWins;
  for (int r = 1; r <= k; r++) {
    if (ways[r])
      maxWins = max(maxWins, r);
  }

  if (initialWins == maxWins)
    ways[maxWins] = -1;
  cout << maxWins << endl << ways[maxWins] << endl;
}