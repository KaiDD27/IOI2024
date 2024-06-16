#include <array>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
int main() {
  cin >> n;
  deque<int> stitches;
  for (int i = 0; i < 6; i++) {
    stitches.push_back(0); // Add the six initial stitches in row 0
  }

  for (int i = 0; i < n; i++) {
    string instruction;
    cin >> instruction;

    char kind = instruction[0];
    int x = stoi(instruction.substr(1));

    if (kind == 'I') {
      int row = stitches.front();
      stitches.pop_front();
      for (int j = 0; j < x; j++) {
        stitches.push_back(row + 1);
      }
    } else {
      int max_row = 0;
      for (int j = 0; j < x; j++) {
        max_row = max(max_row, stitches.front());
        stitches.pop_front();
      }
      stitches.push_back(max_row + 1);
    }
  }

  cout << stitches.size() << endl;
  cout << stitches.back() << endl; // Get youngest element

  return 0;
}