#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, ps, as, hs;
map<ll, array<ll, 2>> pah;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  ll sumA = 0;
  for (int i = 1; i <= n; i++) {
    ll p, a;
    cin >> p >> a;
    sumA += a;
    pah[p] = {a, 10};
  }
  cin >> ps >> as;
  hs = 60;
  pah[ps] = {as, hs};
  auto it = pah.find(ps);

  while (true) {
    if (it != pah.begin()) {
      auto pIt = prev(it);
      pIt->second[1] -= as;
      if (pIt->second[1] <= 0) {
        sumA -= pIt->second[0];
        pah.erase(pIt);
      }
    }
    auto nIt = next(it);
    if (nIt != pah.end()) {
      nIt->second[1] -= as;
      if (nIt->second[1] <= 0) {
        sumA -= nIt->second[0];
        pah.erase(nIt);
      }
    }
    if (pah.size() == 1)
      break;
    hs -= sumA;
    if (hs <= 0)
      break;
  }
  if (hs > 0) {
    cout << "Shadow wins!" << endl;
  } else {
    cout << "We win! Players alive: ";
    for (auto pi : pah)
      if (pi != *it)
        cout << pi.first << " ";
  }
  return 0;
}