// 只通过了 subtask 1,2,3，没有通过 4
#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
struct struc {
  int l;
  int r;
  int c;
};
vector<struc> student;
vector<vector<vector<int>>> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll l, r, n;
  cin >> l >> r >> n;

  student.resize(n + 1);
  int sumL = 0, sumR = 0;
  int ans = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> student[i].c >> student[i].l >> student[i].r;
    if (student[i].l == -1) {
      sumR += student[i].c;
      ans += student[i].r;
      cnt++;
    }
    if (student[i].r == -1) {
      sumL += student[i].c;
      ans += student[i].l;
      cnt++;
    }
  }
  if (sumL > l || sumR > r) {
    cout << "Camp is cancelled" << endl;
    return 0;
  }
  if (cnt == n) {
    cout << ans << endl;
    return 0;
  }

  dp.resize(2, vector<vector<int>>(l + 1, vector<int>(r + 1, INT_MIN)));
  int now = 0, old = 1;
  dp[now][0][0] = 0;
  for (int i = 0; i <= n - 1; i++) {
    swap(now, old);
    fill(dp[now].begin(), dp[now].end(), vector<int>(r + 1, INT_MIN));
    for (int j = 0; j <= l; j++) {
      for (int k = 0; k <= r; k++) {
        if (dp[old][j][k] == INT_MIN) {
          continue;
        }
        if (student[i + 1].l != -1 && j + student[i + 1].c <= l) {
          dp[now][j + student[i + 1].c][k] =
              max(dp[now][j + student[i + 1].c][k],
                  dp[old][j][k] + student[i + 1].l);
        }
        if (student[i + 1].r != -1 && k + student[i + 1].c <= r) {
          dp[now][j][k + student[i + 1].c] =
              max(dp[now][j][k + student[i + 1].c],
                  dp[old][j][k] + student[i + 1].r);
        }
      }
    }
  }
  ans = INT_MIN;
  for (int i = 0; i <= l; i++) {
    for (int j = 0; j <= r; j++) {
      ans = max(ans, dp[now][i][j]);
    }
  }
  if (ans <= 0) {
    cout << "Camp is cancelled" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}