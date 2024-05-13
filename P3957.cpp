#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Cell {
  int position;
  int score;
};

int main() {
  int n, d, k;
  cin >> n >> d >> k;

  vector<Cell> cells(n);
  for (int i = 0; i < n; ++i) {
    cin >> cells[i].position >> cells[i].score;
  }

  // 调整二分搜索的右边界
  int left = 0, right = 1e9; // 假设题目数据范围允许的最大值
  while (left < right) {
    int mid = left + (right - left) / 2;
    bool canAchieve = false;
    vector<int> dp(n, -1e9);

    for (int i = 0; i < n && cells[i].position <= d + mid; ++i) {
      if (cells[i].position >= d - mid) {
        dp[i] = cells[i].score;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (dp[i] < 0)
        continue;
      for (int j = i + 1;
           j < n && cells[j].position <= cells[i].position + d + mid; ++j) {
        if (cells[j].position >= cells[i].position + d - mid) {
          dp[j] = max(dp[j], dp[i] + cells[j].score);
        }
      }
    }

    for (int score : dp) {
      if (score >= k) {
        canAchieve = true;
        break;
      }
    }

    if (canAchieve) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  if (left > 1e9 - 1) { // 检查是否超出了假设的最大值
    cout << -1 << endl;
  } else {
    cout << left << endl;
  }

  return 0;
}