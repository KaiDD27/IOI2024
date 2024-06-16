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
  queue<ll> q;
  distStart.resize(n, LLONG_MAX);
  distStart[0] = 0;
  q.push(0);
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      if (distStart[b] == LLONG_MAX && distShopper[b] >= m) {
        distStart[b] = distStart[a] + 1;
        if (b == n - 1) {
          cout << distStart[n - 1] + 1 << endl;
          return true;
        }
        q.push(b);
      }
    }
  }
  return false;
}
void bfsDist(ll shopper) {
  vector<bool> visited(n, false);
  queue<ll> q;
  q.push(shopper);
  distShopper[shopper] = 0;
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    if (visited[a] == true)
      continue;
    visited[a] = true;
    for (auto b : adj[a]) {
      if (visited[b] == false && (distShopper[a] + 1) < distShopper[b]) {
        distShopper[b] = distShopper[a] + 1;
        if (distShopper[b] < m - 1)
          q.push(b);
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