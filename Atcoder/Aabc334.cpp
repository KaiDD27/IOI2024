#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int b, g;
  cin >> b >> g;
  if (b > g)
    cout << "Bat" << endl;
  else
    cout << "Glove" << endl;
  return 0;
}