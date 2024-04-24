#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<int, int> colorMinDeli;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;
    if (colorMinDeli.count(c))
      colorMinDeli[c] = min(colorMinDeli[c], a);
    else
      colorMinDeli[c] = a;
  }
  int ans = 0;
  for (auto ci : colorMinDeli) {
    ans = max(ans, ci.second);
  }
  cout << ans << endl;
  return 0;
}