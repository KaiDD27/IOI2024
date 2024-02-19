#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;
long long numsP[25];
long long sum = 0;
long long ans = 1000000000007;
long long sumOfGroup1 = 0;
int n;
void calc(int j) {
  if (sumOfGroup1 >= sum - sumOfGroup1) {
    ans = min(ans, abs(2 * sumOfGroup1 - sum));
    return;
  }
  for (int i = 1; i <= n; i++) {
    sumOfGroup1 += numsP[i];
    calc(i + 1);
    sumOfGroup1 -= numsP[i];
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> numsP[i];
    sum += numsP[i];
  }
  calc(0);
  cout << ans << endl;
  return 0;
}