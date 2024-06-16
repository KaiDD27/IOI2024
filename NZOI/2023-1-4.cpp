#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
int maxIntensity, t, n, m;
vector<int> intensities;
vector<vector<tuple<int, int, bool>>> adj;
vector<vector<int>> dp;
vector<int> presumIntensity;
int cost(int time, bool flagShaded, int length) {
  return flagShaded ? 0
                    : presumIntensity[time + length] - presumIntensity[time];
}
int solve(int node, int time) {
  // 因为更大的 time 不影响结果，反正都是用maxIntensity来算了。
  time = min(time, t);
  auto &result = dp[node][time];
  if (result != -1)
    return result;
  if (node == n - 1)
    return result = 0;
  result = INT_MAX;
  if (time < t)
    result = solve(node, time + 1);
  for (auto &[dest, length, flagShaded] : adj[node]) {
    int tmpRes = solve(dest, time + length);
    if (tmpRes == INT_MAX)
      result = min(result, INT_MAX);
    else
      result = min(result, tmpRes + cost(time, flagShaded, length));
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> maxIntensity >> t;
  intensities.resize(t + 500);
  presumIntensity.resize(t + 500);
  for (int i = 0; i < t; i++)
    cin >> intensities[i];
  for (int i = t; i < t + 500; i++)
    intensities[i] = maxIntensity;
  presumIntensity[0] = 0;
  for (int i = 0; i < t + 500; i++)
    presumIntensity[i + 1] = presumIntensity[i] + intensities[i];
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b, d;
    char chS;
    cin >> a >> b >> d >> chS;
    adj[a].push_back({b, d, chS == 'S'});
  }
  dp.resize(n + 1, vector<int>(t + 1, -1));
  cout << solve(0, 0);
}