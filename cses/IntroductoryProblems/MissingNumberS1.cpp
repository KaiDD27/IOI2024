#include <iostream>
using namespace std;
#define endl '\n'
const int MAXN = 200100;
int nums[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int num;
    cin >> num;
    nums[num] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (nums[i] != 1) {
      cout << i;
      break;
    }
  }
  return 0;
}