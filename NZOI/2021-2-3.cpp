#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> c, r;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  c.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> r[i];
  }
  sort(c.begin(), c.end());
  sort(r.begin(), r.end());
  ll minCDist = 0, minRDist = 0;
  for (int i = 0; i < n; i++) {
    ll cMedian = c[n / 2], rMedian = r[n / 2];
    minCDist += abs(c[i] - cMedian);
    minRDist += abs(r[i] - rMedian);
  }
  cout << min(minCDist, minRDist) << endl;
  return 0;
}