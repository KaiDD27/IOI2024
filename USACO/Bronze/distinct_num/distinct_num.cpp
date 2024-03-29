#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N = 0;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  int distinct = 1;
  for (int i = 1; i < N; i++) {
    if (nums[i] != nums[i - 1]) {
      distinct++;
    }
  }
  cout << distinct << endl;

  return 0;
}