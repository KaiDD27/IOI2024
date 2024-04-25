#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
set<ll> setN;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, k;
  cin >> n >> k;
  ll sum = k * (k + 1) / 2;
  for (int i = 0; i < n; i++) {
    ll ni = 0;
    cin >> ni;
    if (ni <= k)
      setN.insert(ni);
  }

  for (auto si : setN) {
    sum -= si;
  }
  cout << sum << endl;
  return 0;
}