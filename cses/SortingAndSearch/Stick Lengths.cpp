#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long ll;
#define endl '\n'

ll p[200100];

int main() {
  ll n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  ll median = p[n / 2];
  for (int i = 0; i < n; i++) {
    ans += abs(median - p[i]);
  }
  cout << ans << endl;
  return 0;
}