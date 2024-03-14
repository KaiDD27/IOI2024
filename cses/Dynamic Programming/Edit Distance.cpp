#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  string strN, strM;
  cin >> strN >> strM;
  n = strN.size(), m = strM.size();
  dp.resize(m + 1);
  for (int j = 0; j <= m; j++)
    dp[j] = j;
  for (int i = 1; i <= n; i++) {
    int leftUp = dp[0];
    dp[0] = i;
    for (int j = 1; j <= m; j++) {
    }
  }

  return 0;
}