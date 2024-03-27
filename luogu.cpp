// 洛谷 P1776：二进制拆分+滚动数组
#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;
int n, C, dp[N];
int w[N], c[N], m[N];
int new_n;                        // 二进制拆分后的新物品总数量
int new_w[N], new_c[N], new_m[N]; // 二进制拆分后新物品
int main() {
  cin >> n >> C;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> c[i] >> m[i];
  // 以下是二进制拆分
  int new_n = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m[i]; j <<= 1) { // 二进制枚举：1,2,4...
      m[i] -= j;                          // 减去已拆分的
      new_c[++new_n] = j * c[i];          // 新物品
      new_w[new_n] = j * w[i];
    }
    if (m[i]) { // 最后一个是余数
      new_c[++new_n] = m[i] * c[i];
      new_w[new_n] = m[i] * w[i];
    }
  }
  // 以下是滚动数组版本的0/1背包
  for (int i = 1; i <= new_n; i++)      // 枚举物品
    for (int j = C; j >= new_c[i]; j--) // 枚举背包容量
      dp[j] = max(dp[j], dp[j - new_c[i]] + new_w[i]);
  cout << dp[C] << endl;
  return 0;
}
