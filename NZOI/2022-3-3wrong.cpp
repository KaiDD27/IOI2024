#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<char> c;
ll factorial(ll x) {
  ll ret = 1;
  for (int i = 2; i <= x; i++)
    ret *= i;
  return ret;
}
void mergeSeries(ll &aWays, ll aCnt, ll bWays, ll bCnt) {
  aWays = aWays * bWays *
          (factorial(aCnt + bCnt) / (factorial(aCnt) * factorial(bCnt)));
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;

  c.resize(n);
  for (auto &ci : c)
    cin >> ci;
  // 加一个墙
  c.push_back('s');
  ll ans = 1;
  ll intervalWays = 1, intervalCnt = 0;
  for (ll i = 0, iPreS = -1, tmpWays = 1, tmpCnt = 0; i <= n; i++) {
    if (c[i] == 's') {
      mergeSeries(intervalWays, intervalCnt, tmpWays, tmpCnt);
      ans *= intervalWays;
      ans %= MOD;
      tmpWays = 1, tmpCnt = 0, intervalWays = 1, intervalCnt = 0;
      iPreS = i;
      continue;
    }
    if (c[i] == 'o') {
      tmpCnt++;
      tmpWays *= tmpCnt;
    } else {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}