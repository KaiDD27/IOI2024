#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
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
  for (int iCoin = 0; iCoin < n; iCoin++) {
    for (int jSum = coin[iCoin]; jSum <= x; jSum++) {
      if (jSum - coin[iCoin] >= 0) {
        dp[jSum] += dp[jSum - coin[iCoin]];
        dp[jSum] %= (ll)(1e9 + 7);
      }
    }
  }
  cout << dp[x] << endl;
}