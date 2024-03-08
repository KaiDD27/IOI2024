#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
vector<int> nums;
int main() {
  int n;
  cin >> n;
  nums.resize(n);
  for (int i = 1; i <= n - 1; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  bool missLast = true;
  for (int i = 1; i < n; i++) {
    if (nums[i] != nums[i - 1] + 1) {
      cout << nums[i] - 1 << endl;
      missLast = false;
      break;
    }
  }
  if (missLast == true)
    cout << n << endl;
  return 0;
}