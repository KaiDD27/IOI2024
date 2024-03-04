#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
vector<int> a;
vector<int> b;
int main() {
  int n, m, k;
  int ans = 0;
  cin >> n >> m >> k;
  a.resize(n);
  b.resize(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0, j = 0; i < m && j < n;) {
    if (abs(b[i] - a[j]) <= k) {
      i++;
      j++;
      ans++;
    } else if (b[i] > a[j]) {
      j++;
    } else if (a[j] > b[i]) {
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}