#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> aFactor(1001), bFactor(1001);
ll powX(ll a, ll x) {
  ll b = 1;
  for (int i = 0; i < x; i++)
    b *= a;
  return b;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll a, b, k;
  cin >> a >> b >> k;
  ll tmpA = a;
  while (tmpA != 1) {
    for (int i = 2; i <= 1000; i++) {
      if (tmpA % i == 0) {
        aFactor[i]++;
        tmpA /= i;
        break;
      }
    }
  }
  ll tmpB = b;
  while (tmpB != 1) {
    for (int i = 2; i <= 1000; i++) {
      if (tmpB % i == 0) {
        bFactor[i]++;
        tmpB /= i;
        break;
      }
    }
  }
  ll miniMultiple = 1;
  for (int i = 2; i <= 1000; i++) {
    if (max(aFactor[i], bFactor[i]) != 0)
      miniMultiple *= (powX(i, max(aFactor[i], bFactor[i])));
  }
  vector<array<ll, 2>> ans;
  ans.push_back({k, 0});
  for (int i = 0; i < miniMultiple / a; i++) {
    for (int j = 0; j <= miniMultiple / b; j++) {
      ll sum = i * a + j * b;
      if (sum == 0)
        continue;
      if (k % sum < sum - k % sum)
        ans.push_back({k % sum, (k / sum) * (i + j)});
      else
        ans.push_back({sum - k % sum, (1 + k / sum) * (i + j)});
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[0][0] << " " << ans[0][1] << endl;
  return 0;
}