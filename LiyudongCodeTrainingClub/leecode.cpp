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
      for (int j = 0; j < cols; j++) {
        while (!st.empty() && height[j] < height[st.top()]) {
          right[st.top()] = j;
          st.pop();
        }
        st.push(j);
      }
      while (!st.empty()) {
        right[st.top()] = cols;
        st.pop();
      }
      for (int j = cols - 1; j >= 0; j--) {
        while (!st.empty() && height[j] <= height[st.top()]) {
          left[st.top()] = j;
          st.pop();
        }
        st.push(j);
      }
      while (!st.empty()) {
        left[st.top()] = -1;
        st.pop();
      }
      for (int j = 0; j < cols; j++) {
        ans = max(ans, (right[j] - left[j] - 1) * height[j]);
      }
    }
    return ans;
  }

private:
  stack<int> st;
};

int main() {
  Solution solution; // Instantiate an object of the Solution class
  vector<vector<char>> matrix = {{'1', '0', '0', '0', '1'},
                                 {'1', '1', '0', '1', '1'},
                                 {'1', '1', '1', '1', '1'}};
  cout << solution.maximalRectangle(matrix) << endl;

  return 0;
}