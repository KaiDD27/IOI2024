#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
int p[200100];

int main() {
  int n, x, cnt = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  for (int i = 0, j = n - 1; i <= j;) {
    if (i == j) {
      cnt++;
      break;
    }
    if (p[j] + p[i] <= x) {
      i++;
      j--;
      cnt++;
    } else {
      j--;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}