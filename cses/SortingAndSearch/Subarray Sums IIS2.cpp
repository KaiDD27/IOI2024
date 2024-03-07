#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
vector<ll> preSum;
unordered_multiset<ll>
    ums; // 因为只是需要返回数量，
         // 所以unordered_map用来实现桶计数类似的效果时间复杂度是最低的，map也满足
// 而不是用multiset或者multimap，那样会超时。
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