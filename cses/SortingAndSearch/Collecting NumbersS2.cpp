#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> x;
vector<int> idx;

int main() {
  int ans = 1, n;
  cin >> n;
  x.resize(n);
  idx.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int i, int j) { return x[i] < x[j]; });
  for (int i = 1; i < n; i++) {
    if (idx[i] < idx[i - 1])
      ans++;
  }
  cout << ans << endl;
  return 0;
}