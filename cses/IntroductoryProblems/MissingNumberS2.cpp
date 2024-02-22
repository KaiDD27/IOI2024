#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
const int MAXN = 200100;
int nums[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> nums[i];
  }
  sort(nums, nums + n);
  nums[n] = n + 1;
  for (int i = 1; i <= n; i++) {
    if (nums[i] != nums[i - 1] + 1) {
      cout << nums[i] - 1;
      break;
    }
  }
  return 0;
}