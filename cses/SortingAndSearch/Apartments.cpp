#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
int N[200100];
int M[200100];

int main() {
  int n, m, k;
  int cnt = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> M[i];
  }
  sort(N, N + n);
  sort(M, M + m);
  for (int i = 0, j = 0; i < m && j < n;) {
    if (abs(M[i] - N[j]) <= k) {
      i++;
      j++;
      cnt++;
    } else if (M[i] > N[j]) {
      j++;
    } else if (N[j] > M[i]) {
      i++;
    }
  }
  cout << cnt << endl;
  return 0;
}