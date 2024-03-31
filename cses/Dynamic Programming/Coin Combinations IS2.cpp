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
  dp.resize(x + 1);
  dp[0] = 1;
  coin.resize(n);
  for (auto &ci : coin)
    cin >> ci;
  for (int iSum = 1; iSum <= x; iSum++) {
    dp[iSum] = 0;
    for (auto ci : coin) {
      if (iSum - ci >= 0) {
        dp[iSum] += dp[iSum - ci];
        dp[iSum] %= MOD;
      }
    }
  }
  cout << dp[x] << endl;
  return 0;
}