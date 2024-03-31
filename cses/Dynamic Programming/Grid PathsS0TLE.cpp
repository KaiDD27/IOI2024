// 暴力搜索
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
const int MOD = 1e9 + 7;
vector<int> dp;
vector<vector<bool>> gridAvailable;
ll dfs(int line, int column) {
  if (line <= 0 || column <= 0 || gridAvailable[line][column] == false)
    return 0;
  if (line == 1 && column == 1)
    return 1;
  return (dfs(line - 1, column) + dfs(line, column - 1)) % MOD;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  gridAvailable.resize(n + 1, vector<bool>(n + 1));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      gridAvailable[i][j] = s[j - 1] == '.' ? true : false;
    }
  }
  cout << dfs(n, n) << endl;
  return 0;
}