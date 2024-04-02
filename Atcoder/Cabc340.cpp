#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
#define endl "\n"
unordered_map<ll, ll> mp;
ll dfs(ll x) {
  // ll totalMoney = 0;
  if (x == 2)
    return 2;
  if (x == 3)
    return 5;
  if (x == 1)
    return 0;
  if (mp[x] != 0)
    return mp[x];

  if (x % 2 == 0) {
    return mp[x] = x + 2 * dfs(x / 2);
  } else {
    return mp[x] = x + dfs(x / 2) + dfs(x / 2 + 1);
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll N;
  cin >> N;

  cout << dfs(N) << endl;
  return 0;
}