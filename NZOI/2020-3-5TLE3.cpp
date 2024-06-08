#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
set<ll> stUnusedColumns;
vector<vector<ll>> grid;
set<pair<ll, ll>> stTieRowsPair;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll r, c;
  cin >> r >> c;
  grid.resize(r + 1, vector<ll>(c + 1));
  for (int i = 1; i <= c; i++) {
    stUnusedColumns.insert(i);
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> grid[i][j];
    }
    if (i != 1)
      stTieRowsPair.insert({i - 1, i});
  }

  while (!stUnusedColumns.empty()) {
    for (auto ci : stUnusedColumns) {
      int flagAscOrDescOrNo = 1;
      bool flagFirst = true;
      for (auto it = stTieRowsPair.begin(); it != stTieRowsPair.end(); it++) {
        if (flagFirst == true) {
          if (grid[it->first][ci] == grid[it->second][ci])
            continue;
          if (grid[it->first][ci] > grid[it->second][ci])
            flagAscOrDescOrNo = 2;
          else if (grid[it->first][ci] < grid[it->second][ci])
            flagAscOrDescOrNo = 1;
          flagFirst = false;
        } else {
          if (grid[it->first][ci] < grid[it->second][ci] &&
              flagAscOrDescOrNo == 2) {
            flagAscOrDescOrNo = 0;
            break;
          }
          if (grid[it->first][ci] > grid[it->second][ci] &&
              flagAscOrDescOrNo == 1) {
            flagAscOrDescOrNo = 0;
            break;
          }
        }
      }
      if (flagAscOrDescOrNo == 1) {
        cout << ci << " asc" << endl;
        stUnusedColumns.erase(ci);
        for (auto it = stTieRowsPair.begin(); it != stTieRowsPair.end();) {
          if (grid[it->first][ci] != grid[it->second][ci]) {
            auto eraseIt = it;
            it++;
            stTieRowsPair.erase(eraseIt);
          } else {
            it++;
          }
        }
        break;
      }
      if (flagAscOrDescOrNo == 2) {
        cout << ci << " desc" << endl;
        stUnusedColumns.erase(ci);
        for (auto it = stTieRowsPair.begin(); it != stTieRowsPair.end();) {
          if (grid[it->first][ci] != grid[it->second][ci]) {
            auto eraseIt = it;
            it++;
            stTieRowsPair.erase(eraseIt);
          } else {
            it++;
          }
        }
        break;
      }
    }
  }
  return 0;
}