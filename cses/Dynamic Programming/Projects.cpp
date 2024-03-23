#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
const int B = 0, A = 1, P = 2;
vector<array<int, 3>> project; // 0=b,1=a,2=p
vector<ll> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  dp.resize(n + 1); // dp[0] = 0是类似墙的一种保护，没有project 的时候最大就是 0
  project.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> project[i][A] >> project[i][B] >> project[i][P];
  sort(project.begin(), project.end()); // sort by ending days
  // 因为a，b 的范围是
  // 10^9,太大了，将这个范围做为第二维会超时，所以需要通过在二分法来查询ending
  // day小于当前project starting day的project 的序号
  for (int i = 1; i <= n; i++) {
    auto it = lower_bound(project.begin(), project.end(),
                          array<int, 3>{project[i][A], 0, 0});
    it--;
    int idx = it - project.begin();
    dp[i] = max(dp[i - 1], dp[idx] + project[i][P]);
  }
  cout << dp[n] << endl;

  return 0;
}