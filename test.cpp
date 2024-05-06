#include <algorithm>
#include <cstdlib>

using namespace std;

int medianThree(int nums[], int left, int right) {
  int mid = (left + right) >> 1;
  if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
    return left;
  else if ((nums[mid] < nums[right]) ^ (nums[mid] < nums[left]))
    return mid;
  else
    return right;
}

void quickSort(int nums[], int left, int right) {
  if ((left >= right))
    return;
  int flag = nums[left + rand() % (right - left + 1)];
  int lessThan = left, i = left, greaterThan = right;
  while (i <= greaterThan) {
    if (nums[i] < flag) {
      swap(nums[i++], nums[lessThan++]);
    } else if (nums[i] > flag) {
      swap(nums[i], nums[greaterThan--]);
    } else if (nums[i] == flag) {
      i++;
    }
  }
  quickSort(nums, left, lessThan - 1);
  quickSort(nums, greaterThan + 1, right);
  return;
}