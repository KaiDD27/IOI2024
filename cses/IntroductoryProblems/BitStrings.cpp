#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * 2;
    if (ans >= (int)pow(10, 9) + 7)
      ans = ans % ((int)pow(10, 9) + 7);
  }
  cout << ans << endl;
  return 0;
}