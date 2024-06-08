#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
set<ll> stUnusedCols;
vector<vector<ll>> grid;
set<ll> stTieRows;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll r, c;
  cin >> r >> c;
  grid.resize(r + 1, vector<ll>(c + 1));
  for (int i = 1; i <= c; i++) {
    stUnusedCols.insert(i);
  }
  for (int i = 1; i <= r; i++) {
    stTieRows.insert(i);
    for (int j = 1; j <= c; j++) {
      cin >> grid[i][j];
    }
  }

  ll lastColumn = 0;
  while (!stUnusedCols.empty()) {
    for (auto ci : stUnusedCols) {
      bool flagAsc = true;
      for (auto it = stTieRows.begin(); it != prev(stTieRows.end()); it++) {
        if (*it + 1 == *next(it) && grid[*it][ci] > grid[*it + 1][ci]) {
          flagAsc = false;
          break;
        }
      }
      if (flagAsc == true) {
        cout << ci << " asc" << endl;
        lastColumn = ci;
        break;
      }

      bool flagDsc = true;
      for (auto it = stTieRows.begin(); it != prev(stTieRows.end()); it++) {
        if (*it + 1 == *next(it) && grid[*it][ci] < grid[*it + 1][ci]) {
          flagDsc = false;
          break;
        }
      }
      if (flagDsc == true) {
        cout << ci << " desc" << endl;
        lastColumn = ci;
        break;
      }
    }
    stUnusedCols.erase(lastColumn);
    set<ll> stNewTieRows;
    for (auto it = stTieRows.begin(); it != prev(stTieRows.end()); it++) {
      if (*it + 1 == *next(it) &&
          grid[*it][lastColumn] == grid[*it + 1][lastColumn]) {
        stNewTieRows.insert(*it);
        stNewTieRows.insert(*it + 1);
      }
    }
    stTieRows = stNewTieRows;
  }
  return 0;
}