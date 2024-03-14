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
  c.resize(n);
  for (auto &ci : c)
    cin >> ci;
  dp.resize(x + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = c[i]; j <= x; j++) {
      if (j - c[i] >= 0) {
        dp[j] += dp[j - c[i]];
        dp[j] %= (ll)(1e9 + 7);
      }
    }
  }
  cout << dp[x] << endl;
}