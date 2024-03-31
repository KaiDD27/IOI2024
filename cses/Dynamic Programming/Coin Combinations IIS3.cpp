#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9 + 7;
vector<ll> dp;
vector<int> coin;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  dp.resize(x + 1);
  dp[0] = 1;
  for (auto ci : coin) {
    for (int jSum = ci; jSum <= x; jSum++) {
      if (jSum - ci >= 0) {
        dp[jSum] += dp[jSum - ci];
        dp[jSum] %= MOD;
      }
    }
  }
  cout << dp[x] << endl;
}