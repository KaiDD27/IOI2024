#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> a;
vector<ll> preSum;
map<int, int> mpRemainder;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  ll ans = 0;
  a.resize(n);
  preSum.resize(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    preSum[i] = sum;
  }
  for (int i = 0; i < n; i++) {
    // 负数求余还可能是负数，通过先求余再加n再求余，则能确保是正数了
    int remainder = (preSum[i] % n + n) % n;
    if (remainder == 0)
      ans++;
    auto it = mpRemainder.find(remainder);
    if (it != mpRemainder.end())
      ans += mpRemainder[remainder];
    mpRemainder[remainder]++;
  }
  cout << ans << endl;
  return 0;
}