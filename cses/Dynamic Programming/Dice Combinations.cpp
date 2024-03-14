#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> way;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  way.resize(n + 1);
  way[0] = 1;
  for (int x = 1; x <= n; x++) {
    for (int d = 1; d <= 6; d++) {
      // 等于 0 表示本次不投。
      if (x - d >= 0) {
        way[x] += way[x - d];
        way[x] %= (ll)(1e9 + 7);
      }
    }
  }
  cout << way[n] << endl;

  return 0;
}