#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    sum += t;
  }
  cout << "It took ";
  ll ret = sum / 60;
  ll remain = sum % 60;
  if (ret > 0) {
    cout << ret << " hour";
    if (ret > 1)
      cout << "s";
  }
  if (ret > 0 && remain != 0)
    cout << " and ";
  if (remain > 0) {
    cout << remain << " minute";
    if (remain > 1)
      cout << "s";
  }
  return 0;
}