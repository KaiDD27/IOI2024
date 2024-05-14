#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
// 定义全局变量
vector<ll> scores;
vector<pair<ll, ll>> positions;
ll numGrids, initialJumpDistance, targetScore;
ll minJumpDistance, maxJumpDistance;

// 检查是否可以通过花费g个金币达到至少k分
bool canAchieveTargetScore(int g) {
  // 计算跳跃的最短和最长距离
  minJumpDistance = initialJumpDistance - g;
  maxJumpDistance = initialJumpDistance + g;
  if (minJumpDistance <= 0)
    minJumpDistance = 1;

  // 初始化分数数组
  scores.assign(numGrids + 1, 0);
  deque<int> dq;       // 定义一个双端队列
  int currentGrid = 0; // 当前待入队的格子编号

  // 遍历每个格子
  for (int i = 1; i <= numGrids; i++) {
    // 移除不满足条件的格子
    while (!dq.empty() &&
           positions[i].first - positions[dq.front()].first > maxJumpDistance) {
      dq.pop_front();
    }
    // 将满足条件的格子加入队列
    for (; currentGrid < i &&
           positions[i].first - positions[currentGrid].first >= minJumpDistance;
         currentGrid++) {
      if (positions[i].first - positions[currentGrid].first > maxJumpDistance)
        continue;
      if (dq.empty()) {
        dq.push_back(currentGrid);
      } else {
        while (!dq.empty() && scores[currentGrid] >= scores[dq.back()]) {
          dq.pop_back();
        }
        dq.push_back(currentGrid);
      }
    }

    // 计算当前格子的分数
    if (!dq.empty()) {
      scores[i] = scores[dq.front()] + positions[i].second;
    } else {
      scores[i] = -999999999999;
    }
    // 检查是否达到目标分数
    if (scores[i] >= targetScore)
      return true;
  }
  return false;
}

int main() {
  int left, right, mid;
  // 读取输入
  cin >> numGrids >> initialJumpDistance >> targetScore;
  positions.resize(numGrids + 1);
  for (int i = 1; i <= numGrids; i++) {
    cin >> positions[i].first >> positions[i].second;
  }

  // 二分查找最小的金币数
  left = 0;
  right = 1005;
  while (left < right) {
    mid = (left + right) / 2;
    if (canAchieveTargetScore(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  // 输出结果
  cout << left;
  return 0;
}
