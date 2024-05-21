#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll s, d, c, p;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> s >> d >> c >> p;
  ll duckCnt = s;
  ll ans = 0;
  while (true) {
    duckCnt += (d - c);
    if (duckCnt > p)
      break;
    ans++;
  }
  cout << ans;

  return 0;
}