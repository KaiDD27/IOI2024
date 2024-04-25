#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> cost;
// 第一维是字符串的长度，第二维是最后一个字符是 0 还是
// 1，第三维存在相同字符的对数（只考虑对数为 0 和 1 的情况，其他情况是非法的）
vector<array<array<ll, 2>, 2>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  cost.resize(n + 1);
  dp.resize(n + 1);
  // 占位符
  string strS = "*";
  string strTmp;
  cin >> strTmp;
  strS += strTmp;
  for (int i = 1; i <= n; i++)
    cin >> cost[i];
  int bitOne = strS[1] == '1' ? 1 : 0;
  int bitTwo = strS[2] == '1' ? 1 : 0;
  if (bitOne == bitTwo) {
    dp[2][bitTwo][1] = 0;
    dp[2][bitTwo][0] = cost[1];
    dp[2][(bitTwo + 1) % 2][1] = cost[2] + cost[1];
    dp[2][(bitTwo + 1) % 2][0] = cost[2];
  } else {
    dp[2][bitTwo][1] = cost[1];
    dp[2][bitTwo][0] = 0;
    dp[2][(bitTwo + 1) % 2][1] = cost[2];
    dp[2][(bitTwo + 1) % 2][0] = cost[2] + cost[1];
  }
  for (int i = 3; i <= n; i++) {
    int bitI = strS[i] == '1' ? 1 : 0;
    int reversebitI = (bitI + 1) % 2;
    dp[i][bitI][0] = dp[i - 1][reversebitI][0];
    dp[i][reversebitI][0] = dp[i - 1][bitI][0] + cost[i];
    dp[i][bitI][1] = min(dp[i - 1][bitI][0], dp[i - 1][reversebitI][1]);
    dp[i][reversebitI][1] =
        cost[i] + min(dp[i - 1][bitI][1], dp[i - 1][reversebitI][0]);
  }
  int bitN = strS[n] == '1' ? 1 : 0;
  int reversebitN = (bitN + 1) % 2;
  cout << min(dp[n][bitN][1], dp[n][reversebitN][1]) << endl;
  return 0;
}