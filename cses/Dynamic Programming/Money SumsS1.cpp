#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<int> x;
vector<bool> dp;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  x.resize(n);
  int sumX = 0;
  for (auto &xi : x) {
    cin >> xi;
    sumX += xi;
  }
  dp.resize(sumX + 1);
  dp[0] = true;
  for (auto xi : x) {
    vector<bool> tmp = dp;
    for (int j = 0; j < sumX; j++) {
      if (tmp[j] == true)
        dp[j + xi] = true;
    }
    dp[xi] = true;
  }
  int ans = 0;
  for (int i = 1; i <= sumX; i++)
    if (dp[i] == true)
      ans++;
  cout << ans << endl;
  for (int i = 1; i <= sumX; i++)
    if (dp[i] == true)
      cout << i << " ";
  return 0;
}