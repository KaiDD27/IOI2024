#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0)
      cout << 'x';
    else
      cout << 'o';
  }
  cout << endl;
  return 0;
}