#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
vector<vector<pair<int, int>>>
    dp; // 因为最后结果要除以二，模的除法涉及逆元，但是可以通过累计多少个
        // MOD 来绕过除法逆元的计算，Pair 中的second元素就是来计算多少个 MOD
        // 的，对二求余即可。

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp.resize(n + 1, vector<pair<int, int>>((n + 1) * n / 2 + 1));
  dp[0][0].first = 1;
  for (int i = 1; i <= n; i++) {
    int sumI = (1 + i) * i / 2;
    for (int j = 0; j <= sumI; j++) {
      if (j > sumI / 2) {
        dp[i][j] = dp[i][sumI - j];
        continue;
      }
      if (i <= j) {
        dp[i][j] = dp[i - 1][j - i];
        dp[i][j].first += dp[i - 1][j].first;
        dp[i][j].second += dp[i - 1][j].second;
        dp[i][j].second %= 2;
        dp[i][j].second += (dp[i][j].first / MOD);
        dp[i][j].second %= 2;
        dp[i][j].first %= MOD;

      } else if (i > j) {
        dp[i][j] = dp[j][j];
      }
    }
  }
  int sumN = (1 + n) * n / 2;
  if (sumN % 2 == 0) {
    cout << (dp[n][sumN / 2].first + (dp[n][sumN / 2].second % 2) * MOD) / 2
         << endl;
  } else
    cout << "0" << endl;

  return 0;
}