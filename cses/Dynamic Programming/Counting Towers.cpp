#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const ll modNum = 1e9 + 7;
// n最大为 1e6,对于每一个行，有两种状态，0代表两个单独的块，1 代表横条
vector<array<ll, 2>> f(1e6 + 10);
vector<ll> towerModulo;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int t;
  cin >> t;
  towerModulo.resize(t);
  f[1][0] = 1, f[1][1] = 1; // 第一行两种状态各有一种选择
  for (ll i = 0, n = 0, maxLine = 1; i < t; i++) {
    cin >> n;
    // 已经计算过的，就直接读取就好
    if (n <= maxLine) {
      towerModulo[i] = (f[n][0] + f[n][1]) % modNum;
      continue;
    }
    // 每次都从之前算过的最大的行+1 开始
    for (ll j = maxLine + 1; j <= n; j++) {
      // 两个单独的块，有四种方式来兼容上一行两个单独的块
      //  有1 种方式来兼容上一行的横条
      // 由于用的是ll所以不用每次加都取模
      f[j][0] = (4 * f[j - 1][0] + f[j - 1][1]) % modNum;
      // 横条有一种方式来兼容上一行两个单独的块
      // 两种方式来兼容上一行的横条
      f[j][1] = (f[j - 1][0] + 2 * f[j - 1][1]) % modNum;
    }
    towerModulo[i] = (f[n][0] + f[n][1]) % modNum;
    maxLine = n;
  }
  for (auto ti : towerModulo)
    cout << ti << endl;
  return 0;
}