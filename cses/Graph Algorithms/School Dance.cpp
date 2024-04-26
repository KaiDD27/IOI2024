// 匈牙利算法
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<bool> girlReversed;
vector<vector<bool>> boyToGirl;
vector<int> girlMatchedBoy;
int n, m, k;
bool dfs(int b) {
  for (int g = 1; g <= m; g++) {
    if (girlReversed[g] == false && boyToGirl[b][g] == true) {
      girlReversed[g] = true;
      // 这个女孩已经匹配过了，则去看看能不能给另一个男孩重新匹配下，如果可以的话，
      // 那就把这个女孩让给当前这男孩，否则则当前男孩没有匹配成功
      if (girlMatchedBoy[g] == 0 || dfs(girlMatchedBoy[g])) {
        girlMatchedBoy[g] = b;
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m >> k;
  girlReversed.resize(m + 1);
  boyToGirl.resize(n + 1, vector<bool>(m + 1));
  girlMatchedBoy.resize(m + 1);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    boyToGirl[a][b] = true;
  }
  int matchedCnt = 0;
  for (int b = 1; b <= n; b++) {
    fill(girlReversed.begin(), girlReversed.end(), false);
    if (dfs(b))
      matchedCnt++;
  }
  cout << matchedCnt << endl;
  for (int g = 1; g <= m; g++)
    if (girlMatchedBoy[g] != 0)
      cout << girlMatchedBoy[g] << " " << g << endl;
  return 0;
}