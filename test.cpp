#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int> skills;
vector<vector<int>> stronger;
int simulate(int p, int i, int j) {
  int wins = 0;
  for (int r = 1; r <= k; r++) {
    int stronger_players = stronger[r][p >> r];
    // Adjust to account for swap of players i and j
    if (p >> r == i >> r) {
      // Player i within sub-bracket
      stronger_players += stronger[0][j] - stronger[0][i];
    }
    if (p >> r == j >> r) {
      // Player j within sub-bracket
      stronger_players += stronger[0][i] - stronger[0][j];
    }
    if (stronger_players == 0)
      wins++;
  }
  return wins;
}

int main() {
  cin >> n >> k;
  skills.resize(n);
  stronger.resize(k + 1, vector<int>(n));
  for (int i = 0; i < n; i++)
    cin >> skills[i];

  int firstLoss = 0;
  int maxWins = 0;
  int ways = 0;

  for (int i = 1; i < n; i++) {
    skills[i] = skills[i] > skills[0];
    if (skills[i] && !firstLoss)
      firstLoss = i;
    stronger[0][i] = skills[i];
  }
  skills[0] = 0;
  stronger[0][0] = 0;

  for (int r = 1; r <= k; r++) {
    for (int m = 0; m < (n >> r); m++) {
      stronger[r][m] = stronger[r - 1][m * 2] + stronger[r - 1][m * 2 + 1];
    }
  }

  int initialWins = simulate(0, 0, 0);
  for (int i = 1; i < n; i++) {
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