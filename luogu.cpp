#include <algorithm>
#include <iostream>

using namespace std;
int stone[50100];

bool check(int NumsRemoved, int shortestJumpDistance, int N) {
  int curr = 0;
  int cnt = 0;
  for (int i = 1; i < N + 2; i++) {
    if (stone[i] - stone[curr] < shortestJumpDistance)
      cnt++;
    else
      curr = i;
  }
  if (NumsRemoved < cnt)
    return false;
  else
    return true;
}
int findMaxShortestJumpDistance(int NumsRemoved, int L, int N) {
  int left = 1, right = L;

  while (left < right) {
    int mid = (left + right + 1) >> 1;
    if (check(NumsRemoved, mid, N) == true)
      left = mid;
    else
      right = mid - 1;
  }

  return left;
}
int main() {
  int L, N, M, ans = 0;
  cin >> L >> N >> M;

  // 构造岩石数组，包含起点和终点。
  for (int i = 1; i <= N; i++)
    cin >> stone[i];
  stone[N + 1] = L;

  // 岩石数组排序,默认按照距离从小到大
  sort(stone, stone + N + 2);

  // 二分法来找最短跳跃距离的最大值
  ans = findMaxShortestJumpDistance(M, L, N);

  // 输出结果
  cout << ans << endl;
}