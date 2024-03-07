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
  ll ans = 0;
  int n;
  cin >> n;
  a.resize(n + 1);
  preSum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    preSum[i] = preSum[i - 1] + a[i];
  }
  // 从 0 开始，这样就不用特殊处理求余得 0 的情况了
  for (int i = 0; i <= n; i++) {
    // 负数求余还可能是负数，通过先求余再加n再求余，则能确保是正数了
    int remainder = (preSum[i] % n + n) % n;
    ans += (mpRemainder[remainder]++); // 如果没有就是加 0
  }
  cout << ans << endl;
  return 0;
}