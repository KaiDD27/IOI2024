// 二进制跳跃 Binary Jumping
#include <array>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
const int MAXD = 30; // ceil(log2(10^9))
// 这里如果用vector<vector<int>> dp;然后   dp.resize(n + 1,
// vector<int>(MAXD));就会超时
// 所以 vector 两层嵌套应该避免内层用 vector，而应该该用
// array，除非长度是不确定的，需要push_back
vector<array<int, MAXD>> dp;

int jump(int x, int k) {
  for (int i = 0; i <= MAXD; i++)
    if (k & (1 << i))
      x = dp[x][i];
  return x;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, q;
  cin >> n >> q;
  dp.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> dp[i][0];

  // 预处理生成二进制跳跃矩阵
  for (int d = 1; d <= MAXD; d++) {
    for (int i = 1; i <= n; i++) {
      dp[i][d] = dp[dp[i][d - 1]][d - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    cout << jump(x, k) << endl;
  }

  return 0;
}