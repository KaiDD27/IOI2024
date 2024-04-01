// 记忆化搜索,超时
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'

// The variables to store the list of books and their prices and values
vector<int> h, s;
vector<vector<int>> dp;

ll dfs(int iBook, int totalPrice) {
  if (dp[iBook][totalPrice] != -1)
    return dp[iBook][totalPrice];
  if (iBook == 0)
    return dp[iBook][totalPrice] = 0;
  ll maxPages = 0;
  if (totalPrice >= h[iBook])
    maxPages = s[iBook] + dfs(iBook - 1, totalPrice - h[iBook]);
  maxPages = max(maxPages, dfs(iBook - 1, totalPrice));
  return dp[iBook][totalPrice] = maxPages;
}

int main() {
  // Fast I/O
  ios::sync_with_stdio(false);
  // Not safe to use cin/cout and scanf/printf together
  cin.tie(nullptr);

  // Input the number of books and the amount of money
  int n, x;
  cin >> n >> x;

  // Resize the vectors to hold the books and their prices and values
  h.resize(n + 1);
  s.resize(n + 1);
  dp.resize(n + 1, vector<int>((x + 1), -1));
  // Input the books and their prices and values
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  // Output the maximum value of books that can be purchased
  cout << dfs(n, x) << endl;
  return 0;
}
