#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> x;
vector<ll> preSum;
map<ll, int> mpPreSum;
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
    mpPreSum[preSum[r - a]]++;
    if (l < r - b) {
      mpPreSum[preSum[l]]--;
      if (mpPreSum[preSum[l]] == 0)
        mpPreSum.erase(preSum[l]);
      l++;
    }
    ans = max(ans, preSum[r] - mpPreSum.begin()->first);
  }
  cout << ans << endl;
  return 0;
}