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
vector<queue<ll>> qs;
void bfsDist() {
  for (int i = 0; i < s; i++) {
    cin >> shoppers[i];
    distShopper[shoppers[i]] = 0;
    qs[i].push(shoppers[i]);
  }
  bool flagAllEmpty = false;
  while (flagAllEmpty == false) {
    flagAllEmpty = true;
    for (int i = 0; i < s; i++) {
      if (!qs[i].empty()) {
        auto a = qs[i].front();
        qs[i].pop();
        for (auto b : adj[a]) {
          if (distShopper[a] + 1 < distShopper[b]) {
            distShopper[b] = distShopper[a] + 1;
            qs[i].push(b);
          }
        }
        if (!qs[i].empty())
          flagAllEmpty = false;
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
  qs.resize(s);
  bfsDist();

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
          return 0;
        }
        q.push(b);
      }
    }
  }
  cout << "SELF_ISOLATE" << endl;

  return 0;
}