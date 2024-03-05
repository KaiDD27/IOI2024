#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> mpA, idx;
int main() {
  int n, x;
  cin >> n >> x;
  mpA.resize(n);
  idx.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> mpA[i];
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int i, int j) { return mpA[i] < mpA[j]; });
  for (int l = 0, r = n - 1; l < r;) {
    int iLeftOfA = idx[l], iRightOfA = idx[r];
    if (mpA[iLeftOfA] + mpA[iRightOfA] == x) {
      cout << iLeftOfA + 1 << " " << iRightOfA + 1 << endl;
      return 0;
    }
    if ((mpA[iLeftOfA] + mpA[iRightOfA] > x)) {
      r--;
    } else {
      l++;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}