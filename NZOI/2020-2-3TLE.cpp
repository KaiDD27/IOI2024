#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, t;
multiset<ll> mtX;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> t;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    ll xi;
    cin >> xi;
    mtX.insert(xi);
  }

  for (int i = 0; i < t; i++) {
    ll smallest = *mtX.begin();
    ll bigest = *mtX.rbegin();
    if (bigest - smallest <= 1) {
      break;
    }
    smallest++;
    bigest--;
    mtX.erase(mtX.begin());
    mtX.erase(prev(mtX.end()));
    mtX.insert(smallest);
    mtX.insert(bigest);
  }
  ll ans = *mtX.rbegin() - *mtX.begin();
  cout << ans << endl;
  return 0;
}