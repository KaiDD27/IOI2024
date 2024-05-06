#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> r;
vector<ll> preSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, q;
  cin >> n >> q;
  r.resize(n);
  preSum.resize(n);
  for (auto &ri : r)
    cin >> ri;
  sort(r.begin(), r.end());
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      preSum[i] = r[i];

    } else {
      preSum[i] = preSum[i - 1] + r[i];
    }
  }
  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    auto it = upper_bound(preSum.begin(), preSum.end(), x);
    cout << it - preSum.begin() << endl;
  }
  return 0;
}