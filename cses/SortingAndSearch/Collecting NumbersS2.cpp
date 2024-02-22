#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

int x[200100];
int idx[200100];

int main() {
  int ans = 1, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    idx[i] = i;
  }
  sort(idx, idx + n, [&](int i, int j) { return x[i] < x[j]; });
  for (int i = 1; i < n; i++) {
    if (idx[i - 1] > idx[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}