#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll x;
  cin >> x;
  ll ans;
  if (x >= 0) {
    ans = x / 10;
    if (x % 10 != 0)
      ans++;
  } else {
    ans = x / 10;
  }
  cout << ans << endl;
  return 0;
}