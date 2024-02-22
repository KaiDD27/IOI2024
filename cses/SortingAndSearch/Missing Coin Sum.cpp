#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

ll x[200100];

int main() {
  ll ans = 0, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  ans = 1;
  for (int i = 0; i < n; i++) {
    if (x[i] > ans)
      break;
    else
      ans += x[i];
  }
  cout << ans << endl;
  return 0;
}