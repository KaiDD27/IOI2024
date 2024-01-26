#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k, bool ascend) {
    vector<int> ans;
    while (!dq.empty())
      dq.pop_back();

    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

      if (ascend) {
        while (!dq.empty() && nums[i] <= nums[dq.back()])
          dq.pop_back();
      } else {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
          dq.pop_back();
      }
      dq.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }
    return ans;
  }

private:
  deque<int> dq;
};

int A, B, N;
int main() {
  cin >> A >> B >> N;
  vector<vector<int>> nums(A, vector<int>(B)),
      maxNums(A, vector<int>(B - N + 1)), minNums(A, vector<int>(B - N + 1));
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      cin >> nums[i][j];
    }
  }
  int ans = 1e9 + 1;
  Solution solotion;
  for (int i = 0; i < A; i++) {
    minNums[i] = solotion.maxSlidingWindow(nums[i], N, true);
    maxNums[i] = solotion.maxSlidingWindow(nums[i], N, false);
  }
  for (int i = 0; i < A - N + 1; i++) {
    for (int j = 0; j < B - N + 1; j++) {
      int maxVal = 0;
      int minVal = 1e9;
      for (int c = i; c < i + N; c++) {
        maxVal = max(maxVal, maxNums[c][j]);
        minVal = min(minVal, minNums[c][j]);
      }
      ans = min(ans, maxVal - minVal);
    }
  }
  cout << ans << endl;
  cout << ans << endl;
  cout << ans << endl;

  return 0;
}
