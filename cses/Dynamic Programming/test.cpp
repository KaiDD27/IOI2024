#include <algorithm>

#include <iostream>
#include <vector>
using namespace std;

int dp[1003][1030], n, m;
const int MOD = 1e9 + 7;

void solve(int x, int y, int mask, int next_mask) {
  if (x == n)
    return;
  if (y >= m) {
    (dp[x + 1][next_mask] += dp[x][mask]) %= MOD;
    return;
  }

  int my_mask = 1 << y;
  if (mask & my_mask) {
    solve(x, y + 1, mask, next_mask);
  } else {
    solve(x, y + 1, mask, next_mask | my_mask);
    if (y + 1 < m && !(mask & (my_mask << 1))) {
      solve(x, y + 2, mask, next_mask);
    }
  }
}

int main() {
  cin >> m >> n;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      solve(i, 0, j, 0);
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
