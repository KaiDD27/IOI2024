#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long; // Using ll as an alias for long long
#define endl "\n"

ll N, M, K, U;
vector<ll> distanceSum;
vector<ll> troutCount;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K >> U;

  distanceSum.resize(N, 0);
  troutCount.resize(N + 1, 0);

  for (ll i = 1; i < N; ++i) {
    ll a, b, w;
    cin >> a >> b >> w;
    distanceSum[i] = distanceSum[i - 1] + w;
  }

  for (ll i = 0; i < M; ++i) {
    ll L, D;
    cin >> L >> D;
    ll leftBound = lower_bound(distanceSum.begin(), distanceSum.end(),
                               distanceSum[L] - D) -
                   distanceSum.begin();
    troutCount[leftBound]++;
    troutCount[L + 1]--;
  }

  for (ll i = 1; i <= N; ++i) {
    troutCount[i] += troutCount[i - 1];
  }

  for (ll i = 0; i < K; ++i) {
    char queryType;
    cin >> queryType;
    if (queryType == 'Q') {
      ll q;
      cin >> q;
      cout << troutCount[q] << endl;
    }
  }

  return 0;
}