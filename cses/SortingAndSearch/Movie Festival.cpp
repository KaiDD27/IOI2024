#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

int a[200100], b[200100], idx[200100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    idx[i] = i;
  }
  sort(idx, idx + n, [&](int i, int j) { return b[i] < b[j]; });
  int ans = 1;
  int currTime = b[idx[0]];
  for (int i = 1; i < n; i++) {
    if (a[idx[i]] >= currTime) {
      ans++;
      currTime = b[idx[i]];
    }
  }
  cout << ans << endl;
  return 0;
}