#include <array>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> t;
vector<vector<int>> adj;
int minTastiness = INT_MAX;
int totalTastiness = 0;
int n, m;

void dfs(int a) {
  int tmpTa = t[a];
  totalTastiness += t[a];
  t[a] = 0;
  for (auto b : adj[a]) {
    if (t[b] == 0)
      continue;
    int nextTastiness = totalTastiness + t[b];
    if (nextTastiness >= m) {
      minTastiness = min(minTastiness, nextTastiness);
      if (minTastiness == m) {
        cout << minTastiness << endl;
        exit(0);
      }
      continue;
    }
    dfs(b);
  }
  t[a] = tmpTa;
  totalTastiness -= t[a];
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  t.resize(n);
  for (auto &ti : t) {
    cin >> ti;
  }
  adj.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (t[0] >= m) {
    cout << t[0] << endl;
    return 0;
  }
  dfs(0);
  cout << minTastiness << endl;
  return 0;
}
/*
10 2000
3 1 4 5 7 6 7 2 6 2000
0 1
1 3
0 2
1 4
1 5
1 6
1 7
1 8
1 9
*/