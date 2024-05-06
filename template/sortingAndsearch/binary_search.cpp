// 全部是双闭区间
// 适用于具备单调性的函数f，在下面的例子中，f 就是单调递增的数组 a[x]>=x
//
//
//  在单调递增序列a中查找满足条件 >=x 的数中最小的一个（即x或x的后继）
// 靠左边取 mid
// 可以通过区间扩大为 [l,r+1]，如果结果为r+1说明无解
// 类似 lower_bound()
// 整数情况下 通过查找>=x+1的书中的最小的一个，来实现upper_bound()的功能

// 双闭区间，所以l==r才找到x，
// 向左取整，需要左边+1，所以必须是小于才能左+1，如果是小于等于，则左边无法加一了，所以只能用小于
// 如果多个等于 x 的值，最后
// l是最小的index，，如果要返回最大的index则应该写成a[mid]<=x l=mid+1,最后再把
// l减 1 就是最大的index了
while (l < r) {
  int mid = (l + r) >> 1;
  if (a[mid] >= x)
    r = mid;
  else
    l = mid + 1;
}

// 在单调递增序列a中查找<=x的数中最大的一个（即x或x的前驱）
// 靠右边取 mid
// 可以通过区间扩大为 [l-1,r]，如果结果为l-1说明无解

// 双闭区间，所以l==r才找到x，
// 向右取整，需要右边-1，所以必须是大于才能右-1，如果是
// 大于等于，则右边无法加一了，所以只能用大于
// 如果存在多个等于 x 的值，最后r 是最大的
// index，如果要找到最小的index,则应该写成a[mid]>=x,r=mid-1,最后再把r+1就是最小的index
while (l < r) {
  int mid = (l + r + 1) >> 1;
  if (a[mid] <= x)
    l = mid;
  else
    r = mid - 1;
}

// 实数域二分，设置eps法
while (l + eps < r) {
  double mid = (l + r) / 2;
  if (calc(mid))
    r = mid;
  else
    l = mid;
}

// 实数域二分，规定循环次数法
for (int i = 0; i < 100; i++) {
  double mid = (l + r) / 2;
  if (calc(mid))
    r = mid;
  else
    l = mid;
}

// 把n本书分成m组，每组厚度之和<=size，是否可行
bool valid(int size) {
  int group = 1, rest = size;
  for (int i = 1; i <= n; i++) {
    if (rest >= a[i])
      rest -= a[i];
    else
      group++, rest = size - a[i];
  }
  return group <= m;
}

// 二分答案，判定“每组厚度之和不超过二分的值”时能否在m组内把书分完
int l = 0, r = sum_of_Ai;
while (l < r) {
  int mid = (l + r) >> 1;
  if (valid(mid))
    r = mid;
  else
    l = mid + 1;
}
cout << l << endl;