#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
// 求最大公约数,辗转相除法
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// 求最小公倍数
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll a, b, k;
  cin >> a >> b >> k;
  if (a < b)
    swap(a, b);
  ll miniDist = k, miniCnt = 0;
  ll miniMultiple = lcm(a, b);
  ll MultiDividA = miniMultiple / a;
  ll MultiDividB = miniMultiple / b;

  for (ll i = 0; i <= MultiDividA; i++) {
    for (ll j = 0; j <= MultiDividB; j++) {
      ll sum = i * a + j * b;
      if (sum == 0)
        continue;
      ll result;
      ll dist;
      if ((k % sum) <= (sum - k % sum)) {
        result = k / sum;
        dist = (k % sum);
      } else {
        result = k / sum + 1;
        dist = (sum - k % sum);
      }
      ll aCnt = i * result;
      ll bCnt = j * result;
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