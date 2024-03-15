#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<vector<ll>> dp;
vector<ll> x;
vector<ll> preSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    preSum[i] = preSum[i - 1] + x[i];
  }
  dp.resize(2, vector<ll>(n + 1));
  int now = 0, old = 1;
  for (int i = 1; i <= n; i++) { // i代表剩余数列的长度
    swap(now, old);
    for (int j = 1; j <= n - i + 1; j++) { // j代表剩余数列的起始位置
      dp[now][j] = max(x[j] + preSum[j + i - 1] - preSum[j] - dp[old][j + 1],
                       x[j + i - 1] + preSum[j + i - 2] - preSum[j - 1] -
                           dp[old][j]); // 一头一尾
    }
  }
  cout << dp[now][1] << endl;
  return 0;
}