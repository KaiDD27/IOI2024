#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector> // Include the <vector> header

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int ans = 0;
    heights.push_back(0);
    for (int height : heights) {
      int accumulation = 0;
      while (!rects.empty() && height <= rects.top().height) {
        accumulation += rects.top().width;
        ans = max(ans, accumulation * rects.top().height);

        rects.pop();
      }
      rects.push({height, 1 + accumulation});
    }
    return ans;
  }

private:
  struct Rectangle {
    int height;
    int width;
    int area() { return height * width; }
  };
  stack<Rectangle> rects;
};

int main() {
  Solution solution; // Instantiate an object of the Solution class
  vector<int> height = {2, 1, 5, 6, 2, 3};
  cout << solution.largestRectangleArea(height) << endl;
  return 0;
}