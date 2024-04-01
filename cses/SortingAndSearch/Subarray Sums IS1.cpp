#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  a.resize(n);
  int ans = 0;
  for (auto &i : a)
    cin >> i;
  for (ll sum = 0, l = 0, r = 0; l < n && r <= n;) {
    if (sum == x)
      ans++;
    if (sum >= x) {
      sum -= a[l++];
    } else if (sum < x) {
      sum += a[r++];
    }
  }
  cout << ans;
  return 0;
}