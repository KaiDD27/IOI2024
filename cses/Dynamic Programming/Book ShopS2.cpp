// 递推
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'

// The variables to store the list of books and their prices and values
vector<int> h, s;
// The 2D vector to store the dp table
vector<vector<int>> dp;

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

  // Input the books and their prices and values
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  // Resize the dp table to have n+1 rows and x+1 columns
  dp.resize(n + 1, vector<int>(x + 1));

  // Initialize the dp table with 0s
  for (int iBook = 1; iBook <= n; iBook++) {
    // For each sumPrice, update the dp table
    for (int sumPrice = 1; sumPrice <= x; sumPrice++) {
      // If we can purchase the book with the current sumPrice
      if (sumPrice - h[iBook] >= 0) {
        // Update the dp table
        dp[iBook][sumPrice] = max(dp[iBook - 1][sumPrice - h[iBook]] + s[iBook],
                                  dp[iBook - 1][sumPrice]);
      } else {
        // Otherwise, copy the previous value
        dp[iBook][sumPrice] = dp[iBook - 1][sumPrice];
      }
    }
  }

  // Output the maximum value of books that can be purchased
  cout << dp[n][x] << endl;
  return 0;
}
