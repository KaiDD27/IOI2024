// 2-SAT is a special case of boolean satisfiability.
// Kosaraju for strongly connected component
// 参见算法竞赛下侧 2-SAT 相关内容
#include <array>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define maxn 12
using namespace std;
vector<int> graph[maxn]; // i表示+不满足时，也就是-满足时; i + n:
                         // -不满足时，也就是+满足时
vector<int> rgraph[maxn];
stack<int> vs;
int comp[maxn];
bool vis[maxn];

void dfs(int x) {
  vis[x] = true;
  for (int i = 0; i < graph[x].size(); i++) {
    int to = graph[x][i];
    if (!vis[to])
      dfs(to);
  }
  vs.push(x);
}

void rdfs(int x, int k) {
  vis[x] = true;
  comp[x] = k;
  for (int i = 0; i < rgraph[x].size(); i++) {
    int to = rgraph[x][i];
    if (!vis[to])
      rdfs(to, k);
  }
}

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    char c1, c2;
    int x1, x2;
    cin >> c1 >> x1 >> c2 >> x2;
    x1--;
    x2--;
    int b1 = c1 == '+' ? 1 : 0;
    int b2 = c2 == '+' ? 1 : 0;

    // a="+-x1" b = "+-x2"
    // 这两个 ～a->b  ~b->a  都需要加入。注意a-~b和b->~a都是不成立的
    // 为了Kosaraju所以有 1反图
    graph[n * (1 - b1) + x1].push_back(n * b2 + x2);
    rgraph[n * b2 + x2].push_back(n * (1 - b1) + x1);
    graph[n * (1 - b2) + x2].push_back(n * b1 + x1);
    rgraph[n * b1 + x1].push_back(n * (1 - b2) + x2);
  }
  for (int i = 0; i < 2 * n; i++) {
    if (!vis[i])
      dfs(i);
  }
  memset(vis, false, sizeof(vis));
  int cnt = 0;

  while (!vs.empty()) {
    auto a = vs.top();
    vs.pop();
    if (!vis[a]) {
      rdfs(a, cnt++);
    }
  }

  vector<char> ans(n);
  for (int i = 0; i < n; i++) {
    if (comp[i] == comp[i + n]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    // 因为后面的依赖性更强是，所以需要根据后面的来确定选择，后面的大则按照我们对
    // i 和 i+n 含义的定义，i+n大就是+为真
    if (comp[i] < comp[i + n]) {
      ans[i] = '+';
    }
    // i 大就是+取反，也就是-
    if (comp[i] > comp[i + n]) {
      ans[i] = '-';
    }
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
}