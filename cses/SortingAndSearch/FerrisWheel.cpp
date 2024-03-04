#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<int> p;

int main() {
  int n, x, ans = 0;
  cin >> n >> x;
  p.resize(n);
  for (auto &i : p) {
    cin >> i;
  }
  sort(p.begin(), p.end());
  for (int i = 0, j = n - 1; i <= j;) {
    if (i == j) {
      ans++;
      break;
    }
    if (p[j] + p[i] <= x) {
      i++;
      j--;
      ans++;
    } else {
      j--;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}