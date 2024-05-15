#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
long long n, k, e[N], sum[N], dp[N];
long long ds[N];              // ds[j] = dp[j-1]-sum[j]
int q[N], head = 0, tail = 1; // 递减的单调队列，队头最大
long long que_max(int j) {
  ds[j] = dp[j - 1] - sum[j];
  while (head <= tail && ds[q[tail]] < ds[j])
    tail--;      // 去掉不合格的队尾
  q[++tail] = j; // j进队尾
  while (head <= tail && q[head] < j - k)
    head++;           // 去掉超过窗口k的队头
  return ds[q[head]]; // 返回队头，即最大的dp[j-1]-sum[j]
}
int main() {
  cin >> n >> k;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> e[i];
    sum[i] = sum[i - 1] + e[i]; // 计算前缀和
  }
  for (int i = 1; i <= n; i++)
    dp[i] = que_max(i) + sum[i]; // 状态转移方程
  cout << dp[n];
}
