#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
ll maxIntensity, t, n, m;
vector<ll> intensities;
vector<vector<tuple<ll, ll, bool>>> adj;
vector<vector<ll>> dp;
vector<ll> presumIntensity;
int cost(ll time, bool flagShaded, ll length) {
  return flagShaded ? 0
                    : presumIntensity[time + length] - presumIntensity[time];
}
int solve(ll node, ll time) {
  // 因为更大的 time 不影响结果，反正都是后面的都用maxIntensity来算了。
  time = min(time, t);
  if (dp[node][time] != -1)
    return dp[node][time];
  if (node == n - 1)
    return dp[node][time] = 0;
  dp[node][time] = INT_MAX;
  if (time < t)
    dp[node][time] = solve(node, time + 1);
  for (auto &[dest, length, flagShaded] : adj[node]) {
    ll tmpRes = solve(dest, time + length);
    if (tmpRes == LLONG_MAX)
      dp[node][time] = min(dp[node][time], LLONG_MAX);
    else
      dp[node][time] =
          min(dp[node][time], tmpRes + cost(time, flagShaded, length));
  }
  return dp[node][time];
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
    ll a, b, d;
    char chS;
    cin >> a >> b >> d >> chS;
    adj[a].push_back({b, d, chS == 'S'});
  }
  dp.resize(n + 1, vector<ll>(t + 1, -1));
  cout << solve(0, 0);
}