#include <algorithm>
#include <iostream>

using namespace std;
long long numsP[25];
long long sum = 0;
long long ans = 1000000000007;
int n;
void calc(int i, long long sumOfGroup1) {
  if (sumOfGroup1 >= sum - sumOfGroup1 || i > n) {
    ans = min(ans, abs(2 * sumOfGroup1 - sum));
    return;
  }
  calc(i + 1, sumOfGroup1 + numsP[i]);
  calc(i + 1, sumOfGroup1);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> numsP[i];
    sum += numsP[i];
  }
  calc(1, 0);
  cout << ans << endl;
  return 0;
}
