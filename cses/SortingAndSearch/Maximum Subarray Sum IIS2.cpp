#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> x;
vector<ll> preSum;
multiset<ll> msPreSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, a, b;
  ll ans = -1e17;
  cin >> n >> a >> b;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (ll i = 1, sum = 0; i <= n; i++) {
    cin >> x[i];
    sum += x[i];
    preSum[i] = sum;
  }
  for (int l = 0, r = a; r <= n; r++) {
    msPreSum.insert(preSum[r - a]);
    if (l < r - b) {
      auto it = msPreSum.find(preSum[l]);
      if (it != msPreSum.end())
        msPreSum.erase(it);
      l++;
    }
    ans = max(ans, preSum[r] - *msPreSum.begin());
  }
  cout << ans << endl;
  return 0;
}