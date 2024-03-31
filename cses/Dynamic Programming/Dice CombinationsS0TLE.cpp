// 暴力搜索
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
ll dfs(ll sumD) {
  if (sumD == 0)
    return 1;
  ll cnt = 0;
  for (int dice = 1; dice <= 6; dice++) {
    if (sumD >= dice) {
      cnt += dfs(sumD - dice);
      cnt %= MOD;
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  cout << dfs(n) << endl;
  return 0;
}