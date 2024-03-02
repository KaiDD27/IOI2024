#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
vector<ll> preA;
map<ll, int> mp; // 因为只是需要返回数量，
                 // 所以map用来实现桶计数类似的效果时间复杂度是最高的，
// 而不是用multiset或者multimap，那样会超时
ll ans = 0;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, x;
  cin >> n >> x;
  a.resize(n);
  preA.resize(n);
  ll preSum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    preSum += a[i];
    preA[i] = preSum;
  }
  for (int i = 0; i < n; i++) {
    if (preA[i] == x)
      ans++;
    auto it = mp.find(preA[i] - x);
    if (it != mp.end()) {
      ans += mp[preA[i] - x];
    }
    mp[preA[i]]++;
  }
  cout << ans << endl;
  return 0;
}