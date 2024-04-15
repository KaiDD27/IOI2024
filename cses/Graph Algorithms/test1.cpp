#include <array>
#include <iostream>
#include <utility>
#include <vector>
#define ll long long
#define pii pair<ll, ll>
#define st first
#define nd second
using namespace std;
const long long INF = 1e18;
const long long N = 2e5 + 5;

int n, q, t[N], in[N], color[N], up[18][N], h[N], End[N];

void dfs(int u) {
  color[u] = 1;
  int v = t[u];
  if (color[v] == 0)
    dfs(v);
  else if (color[v] == 1) {
    color[u] = 2;
    h[u] = 1;
    End[u] = u;
    return;
  }
  color[u] = 2;

  h[u] = h[v] + 1;
  End[u] = End[v];
}

int ANC(int k, int u) {
  for (int i = 17; i >= 0; i--)
    if (k & (1 << i))
      u = up[i][u];
  return u;
}

bool is_anc(int a, int b) { // a -> b
  int delta = h[a] - h[b];
  if (delta < 0)
    return false;
  return ANC(delta, a) == b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    in[t[i]]++;
    up[0][i] = t[i];
  }

  // 初始化 parent 矩阵
  for (int i = 1; i < 18; i++)
    for (int j = 1; j <= n; j++)
      up[i][j] = up[i - 1][up[i - 1][j]];

  for (int i = 1; i <= n; i++)
    if (in[i] == 0)
      dfs(i);
  // 如果存某个连通分量就是个环，没有不在环上的节点，这样就不会存在入度为 0
  // 的节点，所以还需要根据color==0 再遍历一遍
  for (int i = 1; i <= n; i++)
    if (color[i] == 0)
      dfs(i);

  int a, b;
  while (q--) {
    cin >> a >> b;
    int ans = 0;
    if (End[a] != End[b]) {
      cout << -1 << '\n';
      continue;
    }
    if (!is_anc(a, b)) {
      ans += h[a] - 1 + (End[a] != t[End[a]]);
      a = t[End[a]];
    }
    if (h[a] < h[b])
      cout << -1 << '\n';
    else {
      int delta = h[a] - h[b];
      cout << (ANC(delta, a) == b ? ans + delta : -1) << '\n';
    }
  }

  return 0;
}
