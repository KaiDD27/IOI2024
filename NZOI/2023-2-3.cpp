#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n = 0;
vector<vector<ll>> grid;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  grid.resize(3, vector<ll>(3));
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++) {
      cin >> grid[r][c];
      if (grid[r][c] == 0)
        n++;
    }

  return 0;
}