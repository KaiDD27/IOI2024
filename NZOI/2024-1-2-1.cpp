#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  // Ensure a is always the smaller value
  if (a > b)
    swap(a, b);

  // Initialize the best solution: {difference from target, number of boxes}
  pair<ll, ll> best = {k, 0};

  // Iterate through possible numbers of 'a' boxes
  for (int iA = 0; iA < b && iA * a <= k + a; iA++) {
    // Calculate the lower bound for 'b' boxes
    ll lowB = max(0ll, (k - iA * a) / b);
    // Calculate the upper bound for 'b' boxes
    ll highB = lowB + 1;

    // Check the solution with the lower bound of 'b' boxes
    best = min(best, {abs(k - iA * a - lowB * b), iA + lowB});
    // Check the solution with the upper bound of 'b' boxes
    best = min(best, {abs(k - iA * a - highB * b), iA + highB});
  }

  // Output the best solution: difference from target and number of boxes
  cout << best.first << " " << best.second << endl;
}