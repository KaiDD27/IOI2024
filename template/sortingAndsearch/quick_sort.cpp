#include <algorithm>

using namespace std;

/* 快速排序类（中位基准数优化） */
// 选取三个候选元素的中位数
int medianThree(int nums[], int left, int right) {
  // 此处使用异或运算来简化代码
  // 异或规则为 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
  int mid = (left + right) >> 1;
  if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
    return left;
  else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
    return mid;
  else
    return right;
}

void quickSort(int nums[], int left, int right) {
  if (left >= right)
    return;
  // 如果针对伪随机测试数据可能会被hack
  // int flag = nums[left + rand() % (right - left + 1)];

  int flag = medianThree(nums, left, right);

  int lt = left, i = left, gt = right;
  while (i <= gt) {
    if (nums[i] < flag)
      swap(nums[i++], nums[lt++]);
    else if (nums[i] > flag)
      swap(nums[i], nums[gt--]);
    else
      i++;
  } // while结束后lt指向大于等于flag的第一个元素，gt指向小于等于flag的最后一个元素
  quickSort(nums, left, lt - 1);
  quickSort(nums, gt + 1, right);
  return;
}
int main() {
  int nums[5] = {1, 2, 3, 4, 5};
  quickSort(nums, 0, 4);
}