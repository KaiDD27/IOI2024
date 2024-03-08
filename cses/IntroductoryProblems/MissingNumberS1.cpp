#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> nums;
int main() {
  int n;
  cin >> n;
  nums.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int num;
    cin >> num;
    nums[num] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (nums[i] != 1) {
      cout << i;
      break;
    }
  }
  return 0;
}