#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> h, s;
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use ci n/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  h.resize(n + 1);
  s.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  dp.resize(2, vector<int>(x + 1));
  int nowLine = 0, oldLine = 1;
  for (int i = 1; i <= n; i++) {
    swap(nowLine, oldLine);
    for (int j = 1; j <= x; j++) {
      if (j - h[i] >= 0)
        dp[nowLine][j] = max(dp[oldLine][j - h[i]] + s[i], dp[oldLine][j]);
      else
        dp[nowLine][j] = dp[oldLine][j];
    }
  }
  cout << dp[nowLine][x] << endl;
  return 0;
}