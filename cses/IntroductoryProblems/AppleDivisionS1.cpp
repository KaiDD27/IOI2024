#include <algorithm>
#include <iostream>

using namespace std;
long long numsP[25];
long long sum = 0;
long long maxSumOfGroup1 = 0;
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numsP[i];
    sum += numsP[i];
  }
  for (int i = 0; i < 1 << n; i++) {
    long long sumGroup1 = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1)
        sumGroup1 += numsP[j];
    if (sumGroup1 <= sum / 2)
      maxSumOfGroup1 = max(maxSumOfGroup1, sumGroup1);
  }
  cout << sum - 2 * maxSumOfGroup1 << endl;
  return 0;
}