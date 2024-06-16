#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, e, s, m;
vector<vector<ll>> adj;
vector<ll> shoppers;
vector<ll> distShopper;
vector<ll> distStart;

bool bfsE() {
  vector<bool> processed(n, false);
  priority_queue<array<ll, 2>> pq;
  distStart.resize(n, LLONG_MAX);
  distStart[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [d, a] = pq.top();
    pq.pop();
    if (processed[a])
      continue;
    processed[a] = true;
    for (auto b : adj[a]) {
      if (distStart[b] == LLONG_MAX && distShopper[b] >= m) {
        distStart[b] = distStart[a] + 1;
        if (b == n - 1) {
          cout << distStart[n - 1] + 1 << endl;
          return true;
        }
        pq.push({-distStart[b], b});
      }
    }
  }
  return false;
}

void bfsDist(ll shopper) {
  vector<bool> processed(n);
  priority_queue<array<ll, 2>> pq;
  pq.push({0, shopper});
  distShopper[shopper] = 0;
  while (!pq.empty()) {
    auto [d, a] = pq.top();
    pq.pop();
    if (processed[a] == true)
      continue;
    processed[a] = true;
    for (auto b : adj[a]) {
      if (processed[b] == false && (distShopper[a] + 1) < distShopper[b]) {
        distShopper[b] = distShopper[a] + 1;
        if (distShopper[b] < m - 1)
          pq.push({-distShopper[b], b});
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> e;
  adj.resize(n);
  distShopper.resize(n, LLONG_MAX);
  for (int i = 0; i < e; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cin >> s >> m;
  shoppers.resize(s);
  for (auto &si : shoppers)
    cin >> si;
  for (auto si : shoppers) {
    bfsDist(si);
  }
  if (bfsE() == false)
    cout << "SELF_ISOLATE" << endl;
  return 0;
}