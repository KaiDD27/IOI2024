#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  ll sum = 0;
  cin >> sum;
  ans = sum;
  for (int i = 1; i < n; ++i) {
    ll num;
    cin >> num;
    sum = max(sum + num, num);
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}