#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
vector<ll> preSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  a.resize(n + 1);
  preSum.resize(n + 1);
  int ans = 0;
  for (ll i = 1, sum = 0; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    preSum[i] = sum;
  }
  for (ll l = 0, r = 1; l < n && r <= n;) {
    if (preSum[r] - preSum[l] == x)
      ans++;
    if (preSum[r] - preSum[l] >= x) {
      l++;
    } else if (preSum[r] - preSum[l] < x) {
      r++;
    }
  }
  cout << ans;
  return 0;
}