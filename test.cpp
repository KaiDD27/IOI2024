#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
long long f[500005], a[500005][2], n, d, k, ok, lpos, rpos;

bool check(int g) {
  lpos = d - g; // 跳的最短距离
  rpos = d + g; // 跳的最长距离
  if (lpos <= 0)
    lpos = 1;
  memset(f, 0, sizeof(f));
  deque<int> dq; // 定义一个双端队列
  int cur = 0;   // 当前待入队的格子编号
  for (int i = 1; i <= n; i++) {
    for (; cur < i && a[i][0] - a[cur][0] >= lpos; cur++) {
      if (dq.empty())
        dq.push_back(cur);
      else {
        while (!dq.empty() && f[cur] >= f[dq.back()])
          dq.pop_back();
        dq.push_back(cur);
      }
    }
    while (!dq.empty() && a[i][0] - a[dq.front()][0] > rpos)
      dq.pop_front();
    if (!dq.empty())
      f[i] = f[dq.front()] + a[i][1];
    else
      f[i] = -999999999999;
    if (f[i] >= k)
      return 1;
  }
  return 0;
}
int main() {
  int i, ans = -1, l, r, m;
  scanf("%lld%lld%lld", &n, &d, &k);
  for (i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i][0], &a[i][1]);
  l = 0, r = 1005;
  m = (l + r) / 2;
  while (l <= r) {
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
    m = (l + r) / 2;
  }
  cout << ans;
  return 0;
}
