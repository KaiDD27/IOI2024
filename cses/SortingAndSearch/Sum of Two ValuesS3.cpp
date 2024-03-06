#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> a, idx;
int main() {
  int n, x;
  cin >> n >> x;
  a.resize(n);
  idx.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
  for (int l = 0, r = n - 1; l < r;) {
    int iLeftOfA = idx[l], iRightOfA = idx[r];
    if (a[iLeftOfA] + a[iRightOfA] == x) {
      cout << iLeftOfA + 1 << " " << iRightOfA + 1 << endl;
      return 0;
    }
    if ((a[iLeftOfA] + a[iRightOfA] > x)) {
      r--;
    } else {
      l++;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}