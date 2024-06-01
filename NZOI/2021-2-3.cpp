#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> cOfficial, r;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  cOfficial.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> cOfficial[i] >> r[i];
  }
  sort(cOfficial.begin(), cOfficial.end());
  sort(r.begin(), r.end());
  ll minCDist = 0, minRDist = 0;
  for (int i = 0; i < n; i++) {
    ll cMedian = cOfficial[n / 2], rMedian = r[n / 2];
    minCDist += abs(cOfficial[i] - cMedian);
    minRDist += abs(r[i] - rMedian);
  }
  cout << min(minCDist, minRDist) << endl;
  return 0;
}