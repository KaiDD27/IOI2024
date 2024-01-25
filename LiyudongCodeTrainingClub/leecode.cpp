#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <vector> // Include the <vector> header

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> height(cols, 0), right(cols, cols), left(cols, -1);
    int ans = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
      }
      right = vector<int>(cols, cols);
      left = vector<int>(cols, -1);

      stk = stack<int>();
      for (int j = 0; j < cols; j++) {
        while (!stk.empty() && height[j] < height[stk.top()]) {
          right[stk.top()] = j;
          stk.pop();
        }
        stk.push(j);
      }

      stk = stack<int>();

      for (int j = cols - 1; j >= 0; j--) {
        while (!stk.empty() && height[j] <= height[stk.top()]) {
          left[stk.top()] = j;
          stk.pop();
        }
        stk.push(j);
      }

      for (int j = 0; j < cols; j++) {
        ans = max(ans, (right[j] - left[j] - 1) * height[j]);
      }
    }
    return ans;
  }

private:
  stack<int> stk;
};

int main() {
  Solution solution; // Instantiate an object of the Solution class
  vector<vector<char>> matrix = {{'1', '0', '0', '0', '1'},
                                 {'1', '1', '0', '1', '1'},
                                 {'1', '1', '1', '1', '1'}};
  cout << solution.maximalRectangle(matrix) << endl;

  return 0;
}