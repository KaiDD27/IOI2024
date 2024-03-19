#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp(10); // 往前数 9 个数，0 属于原地踏步，不是有效选项。
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    dp[i % 10] = i; // 每次减一，相当于上限了。
    while (tmp != 0) {
      int digit = tmp % 10;
      dp[i % 10] =
          min(dp[i % 10], dp[(i - digit) % 10] + 1); // 单行自我滚动数组
      tmp /= 10;
    }
  }
  cout << dp[n % 10] << endl;
  return 0;
}