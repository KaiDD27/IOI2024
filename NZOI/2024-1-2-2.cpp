#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

// 计算最大公约数（GCD）
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// 计算最小公倍数（LCM）
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b, k;
  cin >> a >> b >> k;

  // 确保 a 始终大于或等于 b
  if (a < b)
    swap(a, b);

  ll miniDist = k, miniCnt = 0;
  ll miniMultiple = lcm(a, b);       // 计算 a 和 b 的最小公倍数
  ll MultiDividA = miniMultiple / a; // a 在最小公倍数中的倍数
  ll MultiDividB = miniMultiple / b; // b 在最小公倍数中的倍数

  // 遍历所有可能的 a 和 b 的组合
  for (ll i = 0; i <= MultiDividA; i++) {
    for (ll j = 0; j <= MultiDividB; j++) {
      ll sum = i * a + j * b;
      if (sum == 0)
        continue;

      ll result, dist;
      // 计算距离 k 的最小距离和所需的倍数
      if ((k % sum) <= (sum - k % sum)) {
        result = k / sum;
        dist = (k % sum);
      } else {
        result = k / sum + 1;
        dist = (sum - k % sum);
      }

      ll aCnt = i * result; // a 的总数
      ll bCnt = j * result; // b 的总数

      // 更新最小距离和最小数量
      if (miniDist > dist) {
        miniDist = dist;
        miniCnt =
            aCnt + bCnt % MultiDividB + (bCnt / MultiDividB) * MultiDividA;
      } else if (miniDist == dist) {
        miniCnt = min(miniCnt, aCnt + bCnt % MultiDividB +
                                   (bCnt / MultiDividB) * MultiDividA);
      }
    }
  }

  cout << miniDist << " " << miniCnt << endl;
  return 0;
}