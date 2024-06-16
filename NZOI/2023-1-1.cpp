#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, k;
  cin >> n >> k;
  vector<ll> d;
  d.resize(n);
  for (auto &di : d)
    cin >> di;
  sort(d.begin(), d.end(), greater<ll>());
  ll ans = 0;
  for (int i = 0; i < k; i++)
    ans += d[i];
  cout << ans << endl;

  return 0;
}