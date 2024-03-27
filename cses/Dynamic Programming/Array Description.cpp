#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int modNum = 1e9 + 7;
vector<int> x;
vector<vector<int>> f;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  x.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  f.resize(2, vector<int>(m + 2)); // 0和m+1做为墙
  int now = 1, old = 0;
  if (x[1] != 0) {
    f[now][x[1]] = 1; // 只有一种
  } else {
    fill(f[now].begin(), f[now].end(), 1);
    f[now][0] = 0;     // 墙赋值为 0
    f[now][m + 1] = 0; // 墙赋值为 0
  }
  // 从第二个数开始到第 n 个数
  for (int i = 2; i <= n; i++) {
    swap(now, old);
    fill(f[now].begin(), f[now].end(), 0);
    if (x[i] != 0) {
      f[now][x[i]] = f[old][x[i]];
      f[now][x[i]] %= modNum;

      f[now][x[i]] += f[old][x[i] - 1];
      f[now][x[i]] %= modNum;

      f[now][x[i]] += f[old][x[i] + 1];
      f[now][x[i]] %= modNum;

    } else { // x[i] == 0
      for (int j = 1; j <= m; j++) {
        f[now][j] = f[old][j];

        f[now][j] += f[old][j - 1];
        f[now][j] %= modNum;

        f[now][j] += f[old][j + 1];
        f[now][j] %= modNum;
      }
    }
    if (x[i] != 0 && f[now][x[i]] == 0) // 剪枝,可剪可不剪
      break;
  }

  if (x[n] != 0)
    cout << f[now][x[n]] << endl;
  else {
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
      sum += f[now][i];
      sum %= modNum;
    }
    cout << sum << endl;
  }
  return 0;
}
