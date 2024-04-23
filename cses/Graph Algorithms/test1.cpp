#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, a, b;
int d[N];
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    d[i] %= (a + b);
  }
  sort(d + 1, d + 1 + n);
  d[n + 1] = d[1] + a + b;
  for (int i = 1; i <= n; i++)
    if (d[i + 1] - d[i] > b) {
      puts("Yes");
      return 0;
    }
  puts("No");
  return 0;
}