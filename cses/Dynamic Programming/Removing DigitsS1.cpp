// 记忆化搜索
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> dp;
int dfs(int x) {
  if (x == 0)
    return 0;
  if (dp[x] != -1)
    return dp[x];
  int tmp = x;
  int minSteps = INT_MAX;
  while (tmp != 0) {
    if (tmp % 10 != 0)
      minSteps = min(minSteps, dfs(x - tmp % 10) + 1);
    tmp /= 10;
  }
  return dp[x] = minSteps;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp.resize(n + 1, -1);
  dp[0] = 0;
  cout << dfs(n) << endl;
  return 0;
}