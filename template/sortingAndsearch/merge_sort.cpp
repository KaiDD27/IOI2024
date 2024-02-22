/**
 * File: merge_sort.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

/* 合并左子数组和右子数组 */
#include <climits>
#include <vector>

using namespace std;

int tmp[INT_MAX];
void merge(vector<int> &nums, int left, int mid, int right) {
  // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
  // 创建一个临时数组 tmp ，用于存放合并后的结果

  // 初始化左子数组和右子数组的起始索引
  int i = left, j = mid + 1 ;
  for (int k = left; k <= right; k++)
    if (j > right || (i <= mid && nums[i] < nums[j]))
      tmp[k] = nums[i++];
    else
      tmp[k] = nums[j++];
  
  // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
  for (int k = left; k <= right; k++) {
    nums[k] = tmp[k];
  }
}

/* 归并排序 */
void mergeSort(vector<int> &nums, int left, int right) {
  // 终止条件
  if (left >= right)
    return; // 当子数组长度为 1 时终止递归
  // 划分阶段
  int mid = left + (right - left) / 2; // 计算中点,要规避left+right爆int的情况
  mergeSort(nums, left, mid);          // 递归左子数组
  mergeSort(nums, mid + 1, right); // 递归右子数组
  // 合并阶段
  merge(nums, left, mid, right);
}
