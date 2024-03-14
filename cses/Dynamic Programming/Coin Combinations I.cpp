#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> dp;
vector<int> c;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  dp.resize(x + 1);
  dp[0] = 1;
  c.resize(n);
  for (auto &ci : c)
    cin >> ci;
  for (int i = 1; i <= x; i++) {
    dp[i] = 0;
    for (auto ci : c) {
      if (i - ci >= 0) {
        dp[i] += dp[i - ci];
        dp[i] %= (ll)(1e9 + 7);
      }
    }
  }
  cout << dp[x] << endl;
  return 0;
}