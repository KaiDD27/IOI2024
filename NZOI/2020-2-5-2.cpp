#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int N, K, w, sol;
vector<int> width;
map<int, int> next_row;

// Function to find the largest key in the map that is not larger than x
int get_next_row(int x) { return (--next_row.upper_bound(x))->second; }

int main() {
  cin >> N >> K;
  next_row[1] = 0; // Initialize the map with the starting position
  width.resize(N + 1);
  while (N--) {
    cin >> w;                  // Read the width of the current item
    int row = get_next_row(w); // Find the appropriate row for this item
    width[row] += w;           // Update the total width used in this row
    sol = max(
        sol,
        row + 1); // Update the solution with the highest row number used so far

    int gap =
        K - width[row]; // Calculate the remaining width in the current row

    // Check if a new range needs to be added to the map
    if (get_next_row(gap + 1) < row + 1) {
      next_row[gap + 1] = row + 1; // Add a new range into the map

      // Delete outdated ranges from the map
      auto it = next_row.upper_bound(gap + 1);
      while (it != next_row.end() && it->second <= row + 1) {
        it = next_row.erase(it);
      }
    }
  }

  cout << sol << '\n'; // Output the minimum number of rows required
}