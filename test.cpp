#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 定义一个结构体来存储每个格子的位置和分数
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

  // 二分搜索最小的金币数 g
  int left = 0, right = d + 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    bool canAchieve = false;
    vector<int> dp(n, -1e9); // dp数组，存储到达每个格子的最大分数

    // 初始化起点
    for (int i = 0; i < n && cells[i].position <= d + mid; ++i) {
      if (cells[i].position >= d - mid) {
        dp[i] = cells[i].score;
      }
    }

    // 动态规划计算到达每个格子的最大分数
    for (int i = 0; i < n; ++i) {
      if (dp[i] < 0)
        continue; // 如果当前格子不可达，则跳过
      for (int j = i + 1;
           j < n && cells[j].position <= cells[i].position + d + mid; ++j) {
        if (cells[j].position >= cells[i].position + d - mid) {
          dp[j] = max(dp[j], dp[i] + cells[j].score);
        }
      }
    }

    // 检查是否有任何路径可以达到或超过 k 分
    for (int score : dp) {
      if (score >= k) {
        canAchieve = true;
        break;
      }
    }

    if (canAchieve) {
      right = mid; // 尝试更少的金币
    } else {
      left = mid + 1; // 需要更多的金币
    }
  }

  // 输出结果
  if (left > d) {
    cout << -1 << endl; // 如果金币数超过了 d+1，说明无法达到 k 分
  } else {
    cout << left << endl;
  }

  return 0;
}