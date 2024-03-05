#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define endl '\n'

vector<ll> p;
int main() {
  ll n, ans = 0;
  cin >> n;
  for (auto &i : p)
    cin >> i;
  sort(p.begin(), p.end());
  ll median = p[n / 2];
  for (int i = 0; i < n; i++) {
    ans += abs(median - p[i]);
  }
  cout << ans << endl;
  return 0;
}