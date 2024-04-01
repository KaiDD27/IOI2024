#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
vector<ll> preSum;
unordered_multiset<ll> ums;
ll ans = 0;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, x;
  cin >> n >> x;
  a.resize(n);
  preSum.resize(n);
  for (ll i = 0, sum = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    preSum[i] = sum;
  }
  for (int i = 0; i < n; i++) {
    if (preSum[i] == x)
      ans++;
    ans += ums.count(preSum[i] - x);
    ums.insert(preSum[i]);
  }
  cout << ans << endl;
  return 0;
}