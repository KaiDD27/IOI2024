#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

int a[200100];
int idx[200100];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[i] = i;
  }
  sort(idx, idx + n, [&](int i, int j) { return a[i] < a[j]; });
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[idx[l]] + a[idx[r]] == x) {
      cout << idx[l] + 1 << " " << idx[r] + 1 << endl;
      return 0;
    }
    if ((a[idx[l]] + a[idx[r]] > x)) {
      r--;
    } else {
      l++;
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}