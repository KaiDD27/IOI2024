#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  ll ans;
  cin >> ans;
  for (int i = 1; i < n; i++) {
    ll tmp;
    cin >> tmp;
    if (i % 3 == 1)
      ans += tmp;
    if (i % 3 == 2)
      ans -= tmp;
    if (i % 3 == 0)
      ans *= tmp;
  }
  cout << ans << endl;
  return 0;
}