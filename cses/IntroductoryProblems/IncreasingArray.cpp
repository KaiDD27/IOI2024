#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  int prev = 0, curr = 0;
  cin >> curr;
  for (int i = 1; i < n; i++) {
    prev = curr;
    cin >> curr;
    ans += (prev - curr > 0 ? prev - curr : 0);
    curr = max(prev, curr);
  }
  cout << ans << endl;
  return 0;
}