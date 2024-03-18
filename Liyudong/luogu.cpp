#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k, bool ascend) {
    vector<int> ans;
    while (!dq.empty()) // Clear the deque
      dq.pop_back();

    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() <= i - k) // Remove elements that are out of the sliding window
        dq.pop_front();

      if (ascend) {
        while (!dq.empty() && nums[i] <= nums[dq.back()]) // Remove elements that are smaller than the current element
          dq.pop_back();
      } else {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) // Remove elements that are larger than the current element
          dq.pop_back();
      }
      dq.push_back(i); // Add the current element to the deque
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]); // Add the maximum/minimum element in the sliding window to the answer
    }
    return ans;
  }

private:
  deque<int> dq; // Deque to store indices of elements in the sliding window
};

int A, B, N;
int main() {
  cin >> A >> B >> N;
  vector<vector<int>> nums(A, vector<int>(B)),
      maxNums(A, vector<int>(B - N + 1)), minNums(A, vector<int>(B - N + 1));
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      cin >> nums[i][j]; // Input the elements of the matrix
    }
  }
  int ans = 1e9 + 1; // Initialize the answer with a large value
  Solution solotion; // Create an instance of the Solution class
  for (int i = 0; i < A; i++) {
    minNums[i] = solotion.maxSlidingWindow(nums[i], N, true); // Calculate the maximum sliding window for ascending order
    maxNums[i] = solotion.maxSlidingWindow(nums[i], N, false); // Calculate the maximum sliding window for descending order
  }
  for (int i = 0; i < A - N + 1; i++) {
    for (int j = 0; j < B - N + 1; j++) {
      int maxVal = 0; // Initialize the maximum value in the sliding window
      int minVal = 1e9; // Initialize the minimum value in the sliding window
      for (int c = i; c < i + N; c++) {
        maxVal = max(maxVal, maxNums[c][j]); // Update the maximum value
        minVal = min(minVal, minNums[c][j]); // Update the minimum value
      }
      ans = min(ans, maxVal - minVal); // Update the answer with the minimum difference between the maximum and minimum values
    }
  }
  cout << ans << endl; // Output the answer
  return 0;
}
