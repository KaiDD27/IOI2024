#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  ll sum = 0;
  ll t[n];
  ll maxA = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    maxA = max(maxA, t[i]);
    sum += t[i];
  }
  ll ans = max(maxA * 2, sum);
  cout << ans << endl;
  return 0;
}