/*
 * This C++ program solves the "Book Shop" problem from the CSES
 * website. The problem can be found at:
 * https://cses.fi/problemset/task/1629/
 *
 * Problem description:
 * Given a list of books with their prices and values, find the maximum
 * value of books that can be purchased with a given amount of money.
 *
 * Input:
 * The first line contains two integers n and x, the number of books
 * and the amount of money respectively. The next n lines contain two
 * integers h[i] and s[i], the price and value of the i-th book.
 *
 * Output:
 * The maximum value of books that can be purchased.
 */
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

  // Resize the dp table to have two rows and x+1 columns
  dp.resize(2, vector<int>(x + 1));

  // Initialize the dp table with 0s
  int nowLine = 0, oldLine = 1;
  for (int iBook = 1; iBook <= n; iBook++) {
    // Swap the nowLine and oldLine
    swap(nowLine, oldLine);
    // For each sumPrice, update the dp table
    for (int sumPrice = 1; sumPrice <= x; sumPrice++) {
      // If we can purchase the book with the current sumPrice
      if (sumPrice - h[iBook] >= 0) {
        // Update the dp table
        dp[nowLine][sumPrice] = max(dp[oldLine][sumPrice - h[iBook]] + s[iBook],
                                    dp[oldLine][sumPrice]);
      } else {
        // Otherwise, copy the previous value
        dp[nowLine][sumPrice] = dp[oldLine][sumPrice];
      }
    }
  }

  // Output the maximum value of books that can be purchased
  cout << dp[nowLine][x] << endl;
  return 0;
}
