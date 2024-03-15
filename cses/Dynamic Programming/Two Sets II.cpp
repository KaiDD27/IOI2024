#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp.resize(n + 1, vector<int>((n + 1) * n / 2 + 1));
  for (int i = 1; i <= n; i++) {
    int sumI = (1 + i) * i / 2;
    int sumIminusOne = (1 + i - 1) * (i - 1) / 2;
    for (int j = 1; j <= sumI; j++) {
      if (j > sumI / 2) {
        dp[i][j] = dp[i][sumI - j];
        continue;
      }

      if (i <= j) {
        dp[i][j] = dp[i - 1][j - i];
        if (j - i + j != sumIminusOne) {
          dp[i][j] += dp[i - 1][j];
        }
      } else if (i > j) {
        dp[i][j] = dp[j][j];
      }
    }
  }
  return 0;
}