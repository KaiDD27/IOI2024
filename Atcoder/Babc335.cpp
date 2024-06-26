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
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= n; b++) {
      for (int c = 0; c <= n; c++) {
        if (a + b + c <= n)
          cout << a << " " << b << " " << c << endl;
      }
    }
  }
  return 0;
}