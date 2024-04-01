#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
unordered_map<ll, ll> umpNumCount;
vector<ll> x;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll ans = 0;
  int n, k;
  cin >> n >> k;
  x.resize(n);
  for (auto &i : x) {
    cin >> i;
  }
  for (ll l = 0, r = 0; l < n && r <= n;) {
    int distinct = umpNumCount.size();
    if (distinct <= k) {
      ans += (r - l);
    }
    if (distinct <= k) {
      if (r == n)
        break;
      umpNumCount[x[r]]++;
      r++;
    } else {
      umpNumCount[x[l]]--;
      if (umpNumCount[x[l]] == 0) {
        umpNumCount.erase(x[l]);
      }
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}