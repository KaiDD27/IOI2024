/*
https://codeforces.com/contest/863/problem/B
inputCopy
2
1 2 3 4
outputCopy
1
inputCopy
4
1 3 4 6 3 4 100 200
outputCopy
5
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;
int main(void) {
  cin >> N;
  nums.resize(2 * N);
  for (int i = 0; i < 2 * N; i++) cin >> nums[i];
  sort(nums.begin(), nums.end());
  int ans = 1e9;
  for (int i = 0; i < 2 * N - 1; i++) {
    for (int j = i + 1; j < 2 * N; j++) {
      int first = 0;
      int instab = 0;
      for (int k = 0; k < 2 * N; k++) {
        if (k == i || k == j) continue;
        if (first == 0)
          first = nums[k];
        else {
          instab += (nums[k] - first);
          first = 0;
        }
      }
      ans = min(ans,instab);
    }
  }
  cout << ans << endl;
}