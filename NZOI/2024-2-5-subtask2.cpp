#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long; // 使用ll作为long long的别名
#define endl "\n"

ll N, M, K, U;
vector<pair<ll, ll>> parent;
vector<ll> troutCount;

void addTrout(ll position, ll distance) {
  while (distance >= 0) {
    troutCount[position]++;
    if (position == 0)
      break;
    distance -= parent[position].second;
    position = parent[position].first;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K >> U;

  parent.resize(N, {-1, 0});
  troutCount.resize(N, 0);

  for (ll i = 0; i < N - 1; i++) {
    ll a, b, w;
    cin >> a >> b >> w;
    parent[b] = {a, w};
  }

  for (ll i = 0; i < M; i++) {
    ll L, D;
    cin >> L >> D;
    addTrout(L, D);
  }

  for (ll i = 0; i < K; i++) {
    char queryType;
    cin >> queryType;
    if (queryType == 'Q') {
      ll q;
      cin >> q;
      cout << troutCount[q] << endl;
    } else {
      ll L, D;
      cin >> L >> D;
      addTrout(L, D);
    }
  }

  return 0;
}
