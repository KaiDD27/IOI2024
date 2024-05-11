#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>
#define N 1000005
using namespace std;
int A, B, C, m, s[N];
int X1[N], X2[N], Y1[N], Y2[N], Z1[N], Z2[N];
int d[N], l, r, sub[N];
int num(int x, int y, int z) {
  if (x > A || y > B || z > C)
    return 0;
  return ((x - 1) * B + y - 1) * C + z;
} // 将三维转化成一维
void xxs(int x, int y, int z, int d) { sub[num(x, y, z)] += d; }
bool pre() {
  // 三个方向计算前缀和
  for (int i = 1; i <= A; i++)
    for (int j = 1; j <= B; j++)
      for (int k = 1; k <= C; k++)
        xxs(i, j, k + 1, sub[num(i, j, k)]);
  for (int i = 1; i <= A; i++)
    for (int k = 1; k <= C; k++)
      for (int j = 1; j <= B; j++)
        xxs(i + 1, j, k, sub[num(i, j, k)]);
  for (int j = 1; j <= B; j++)
    for (int k = 1; k <= C; k++)
      for (int i = 1; i <= A; i++)
        xxs(i, j + 1, k, sub[num(i, j, k)]);
  for (int i = 1; i <= A * B * C; i++)
    if (sub[i] > s[i])
      return 1;
  return 0;
}
bool check(int x) {
  memset(sub, 0, sizeof(sub)); // 记住这里要清空，不然之前的还会留在数组中
  for (int i = 1; i <= x; i++) {
    xxs(X1[i], Y1[i], Z1[i], d[i]);
    xxs(X2[i] + 1, Y1[i], Z1[i], -d[i]);
    xxs(X1[i], Y1[i], Z2[i] + 1, -d[i]);
    xxs(X2[i] + 1, Y1[i], Z2[i] + 1, d[i]);
    xxs(X1[i], Y2[i] + 1, Z1[i], -d[i]);
    xxs(X2[i] + 1, Y2[i] + 1, Z1[i], d[i]);
    xxs(X1[i], Y2[i] + 1, Z2[i] + 1, d[i]);
    xxs(X2[i] + 1, Y2[i] + 1, Z2[i] + 1, -d[i]);
  } // 对sub数组进行差分
  return pre();
}
int main() {
  cin >> A >> B >> C >> m;
  for (int i = 1; i <= A * B * C; i++)
    cin >> s[i];
  for (int i = 1; i <= m; i++)
    cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i] >> Z1[i] >> Z2[i] >> d[i];
  int l = 1, r = m;
  while (l + 1 < r) { // 二分答案，取临界点
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}
