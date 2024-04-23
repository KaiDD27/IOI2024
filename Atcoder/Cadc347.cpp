#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> remain;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    remain.push_back(d % (a + b));
  }
  sort(remain.begin(), remain.end());
  // 把最小的值加上整个区间插入最后
  remain.push_back(remain[0] + a + b);
  if (n == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (remain[i] - remain[i - 1] > b) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}