// 暴力搜索
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
int dfs(int x) {
  if (x == 0)
    return 0;
  int tmp = x;
  int minSteps = INT_MAX;
  while (tmp != 0) {
    if (tmp % 10 != 0)
      minSteps = min(minSteps, dfs(x - tmp % 10) + 1);
    tmp /= 10;
  }
  return minSteps;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  cout << dfs(n) << endl;
  return 0;
}