#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  ll sum = 10;
  for (int i = 0; i < n; i++) {
    ll cnt;
    cin >> cnt;
    sum += cnt;
  }
  if (sum == 10)
    cout << "She's got them all" << endl;
  else
    cout << 10 - sum << endl;
  return 0;
}