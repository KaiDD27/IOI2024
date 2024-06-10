#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, x, y, z;
  cin >> n >> x >> y >> z;
  if ((z > x && z < y) || (z < x && z > y))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}