#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
vector<ll> a, b;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  a.resize(n);
  b.resize(n);
  ll sumA = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sumA += a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, sumA - a[i] + b[i]);
  }
  cout << ans << endl;
  return 0;
}