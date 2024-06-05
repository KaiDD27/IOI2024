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

void bfsDist() {
  queue<ll> q;
  for (int i = 0; i < s; i++) {
    cin >> shoppers[i];
    distShopper[shoppers[i]] = 0;
    q.push(shoppers[i]);
  }
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    for (auto b : adj[a]) {
      if (distShopper[a] + 1 < distShopper[b]) {
        distShopper[b] = distShopper[a] + 1;
        q.push(b);
      }
    }
  }
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
  bfsDist();
  if (bfsE() == false)
    cout << "SELF_ISOLATE" << endl;
  return 0;
}