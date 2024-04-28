#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
// 第一维：已经经过 前 i 个字符串集合 第二维：已完成前面 j 个字符的拼接
vector<vector<int>> dp;
vector<vector<string>> a;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strT;
  cin >> strT;
  int n;
  cin >> n;
  a.resize(n + 1);
  dp.resize(n + 1, vector<int>(strT.length() + 1, n + 2));
  for (int i = 1; i <= n; i++) {
    int aCnt;
    cin >> aCnt;
    while (aCnt--) {
      string str;
      cin >> str;
      a[i].push_back(str);
    }
  }
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= strT.length(); j++) {
      dp[i][j] = dp[i - 1][j];
      for (auto si : a[i]) {
        if (j >= si.length() && si == strT.substr(j - si.length(), si.length()))
          dp[i][j] = min(dp[i][j], dp[i - 1][j - si.length()] + 1);
      }
    }
  }
  if (dp[n][strT.length()] <= n)
    cout << dp[n][strT.length()] << endl;
  else
    cout << -1 << endl;

  return 0;
}