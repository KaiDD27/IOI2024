#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
unordered_map<ll, ll> mpValCount;
vector<ll> x;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  x.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  ll l = 0, r = 0, ans = 0;
  while (l < n && r < n) {
    int distinct = mpValCount.size();
    if (distinct < k) {
      mpValCount[x[r]]++;
      r++;
      ans += (r - l);
    } else if (distinct == k) {
      auto it = mpValCount.find(x[r]);
      if (it != mpValCount.end()) {
        mpValCount[x[r]]++;
        r++;
        ans += (r - l);
      } else {
        mpValCount[x[l]]--;
        if (mpValCount[x[l]] == 0) {
          mpValCount.erase(x[l]);
        }
        l++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}