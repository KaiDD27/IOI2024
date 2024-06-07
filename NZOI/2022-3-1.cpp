#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, m;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  vector<bool> isLightOn(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % j == 0)
        isLightOn[i] = !isLightOn[i];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += isLightOn[i];
  cout << ans << endl;
  return 0;
}