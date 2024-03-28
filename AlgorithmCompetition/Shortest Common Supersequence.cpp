// https://www.geeksforgeeks.org/shortest-common-supersequence/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<int>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string str1, str2;
  cin >> str1 >> str2;
  dp.resize(str1.length() + 1, vector<int>(str2.length() + 1, 0));
  // 先求最长公共子序列 longest common subsequence的长度
  for (int i = 1; i <= str1.length(); i++) {
    for (int j = 1; j <= str2.length(); j++) {
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  // 回溯LCS的同时加上str1和str2特有的字符，就是所求的shortest common
  // supersequence
  string scs = "";
  int i = str1.length(), j = str2.length();
  while (i > 0 && j > 0) {
    if (str1[i - 1] == str2[j - 1]) {
      scs.push_back(str1[i - 1]);
      i--;
      j--;
    } else {
      if (dp[i][j - 1] >= dp[i - 1][j]) {
        scs.push_back(str2[j - 1]);
        j--;
      } else {
        scs.push_back(str1[i - 1]);
        i--;
      }
    }
  }
  while (i > 0) {
    scs.push_back(str1[i - 1]);
    i--;
  }
  while (j > 0) {
    scs.push_back(str2[j - 1]);
    j--;
  }
  reverse(scs.begin(), scs.end());
  cout << scs << endl;
  return 0;
}