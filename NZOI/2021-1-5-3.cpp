#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 定义一个三维动态数组，用于存储动态规划的结果
vector<vector<vector<int>>> dp;

// 定义一个二维数组，用于存储学生的信息
vector<vector<int>> students;

int main() {
  int l, r, n;
  // 输入左边和右边的资源数量
  cin >> l >> r;
  // 输入学生的数量
  cin >> n;
  // 初始化动态规划数组
  dp = vector<vector<vector<int>>>(
      n + 1, vector<vector<int>>(l + 1, vector<int>(r + 1, INT_MIN)));
  // 初始化学生数组
  students = vector<vector<int>>(n + 1, vector<int>(3));
  // 输入每个学生的信息
  for (int i = 1; i <= n; ++i) {
    cin >> students[i][0] >> students[i][1] >> students[i][2];
  }

  // 基础情况：当没有学生时，结果为0
  for (int left = 0; left <= l; ++left) {
    for (int right = 0; right <= r; ++right) {
      dp[0][left][right] = 0;
    }
  }

  // 迭代计算动态规划数组
  for (int idx = 1; idx <= n; idx++) {
    for (int left = 0; left <= l; ++left) {
      for (int right = 0; right <= r; ++right) {
        // 如果当前学生的第一个条件满足，并且剩余的左边资源足够
        if (students[idx][1] > 0 && left >= students[idx][0]) {
          dp[idx][left][right] = max(
              dp[idx][left][right],
              dp[idx - 1][left - students[idx][0]][right] + students[idx][1]);
        }
        // 如果当前学生的第二个条件满足，并且剩余的右边资源足够
        if (students[idx][2] > 0 && right >= students[idx][0]) {
          dp[idx][left][right] = max(
              dp[idx][left][right],
              dp[idx - 1][left][right - students[idx][0]] + students[idx][2]);
        }
      }
    }
  }

  // 计算结果并输出
  int result = dp[n][l][r];
  if (result > -1) {
    cout << result << endl;
  } else {
    cout << "Camp is cancelled" << endl;
  }
  return 0;
}
