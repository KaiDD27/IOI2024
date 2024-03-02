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
  int l = 0, r = 0;
  ll sum = 0;
  while (l < n && r <= n) {
    if (sum > x) {
      sum -= a[l];
      l++;
    } else if (sum < x) {
      if (r < n)
        sum += a[r];
      r++;
    }
    if (sum == x) {
      ans++;
      sum -= a[l];
      l++;
    }
  }
  cout << ans;
  return 0;
}