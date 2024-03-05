#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<ll> x;
int main() {
  ll ans = 0, n;
  cin >> n;
  for (auto &i : x)
    cin >> i;
  sort(x.begin(), x.end());
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