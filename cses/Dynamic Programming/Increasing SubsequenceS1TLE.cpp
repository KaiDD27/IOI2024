#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> x;
vector<int> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  dp.resize(n + 1, 1);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (x[i] > x[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;

  return 0;
}