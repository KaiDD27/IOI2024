#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define int long long

int dp[20][10][2][2]; // DP array with dimensions for position, previous digit,
                      // leading zeroes, and tight

// Function to compute the number of valid numbers up to a given digit
int solve(const string &num, int pos, int prev, bool leading_zero, bool tight) {
  if (pos == num.size())
    return 1; // Base case: if at the end, count as 1 valid number
  if (dp[pos][prev][leading_zero][tight] != -1)
    return dp[pos][prev][leading_zero][tight]; // Memoization check

  int limit =
      tight ? (num[pos] - '0') : 9; // Determine the limit for the current digit
  int ways = 0;

  for (int dig = 0; dig <= limit; ++dig) {
    if (dig == prev && !leading_zero)
      continue; // Skip if the digit is the same as the previous non-zero digit
    ways += solve(num, pos + 1, dig, leading_zero && dig == 0,
                  tight && dig == limit);
  }

  return dp[pos][prev][leading_zero][tight] =
             ways; // Store and return the computed value
}

int countValidNumbers(int n) {
  string num = to_string(n);
  memset(dp, -1, sizeof(dp));          // Initialize DP array with -1
  return solve(num, 0, 0, true, true); // Start the DP with the first digit
}

int32_t main() {
  int a, b;
  cin >> a >> b;
  int res = countValidNumbers(b) -
            (a ? countValidNumbers(a - 1) : 0); // Calculate result for [a, b]
  cout << res << endl;
  return 0;
}