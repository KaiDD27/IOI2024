#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<char> c;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  c.resize(n);
  for (auto &ci : c)
    cin >> ci;
  ll ans = 1;
  ll interval = vector<char> interval;
  for (int i = 0, iPreS = -1; i < n; i++) {

    if (c[i] == 's') {

      iPreS = i;
      interval.clear();
      continue;
    }
    interval.push_back(c[i]);
    if (c[i] == 'o') {
      ans *= (i - iPreS);
    }
  }

  return 0;
}