// Dinic算法
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to;
  int nex;
  int weight;
  int flow;
};

vector<Edge> e;
vector<int> head;
int edgeCnt = 1;
vector<int> level, next_edge;
vector<int> now;
void addEdge(int a, int b, int w) {
  edgeCnt++;
  e[edgeCnt] = {b, head[a], w, 0};
  head[a] = edgeCnt;
}

// 广度优先搜索,用于计算节点的层次
bool bfs(int s, int t) {
  fill(level.begin(), level.end(), -1);
  queue<int> q;
  q.push(s);
  level[s] = 0;
  now[s] = head[s];
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int i = head[a]; i > 0; i = e[i].nex) {
      auto b = e[i].to;
      // 如果节点 e.to 未访问过且边的流量小于容量,则将其加入队列
      if (level[b] == -1 && e[i].flow < e[i].weight) {
        q.push(b);
        now[b] = head[b];
        level[b] = level[a] + 1;
      }
    }
  }
  // 如果汇点的层次不小于0,说明存在增广路径
  return level[t] >= 0;
}

// 深度优先搜索,用于寻找增广路径并更新正向反向流
int dfs(int a, int flow, int t) {
  if (a == t) {
    return flow;
  }
  // 弧优化，在这一条dfs
  // 寻找增广路径的过程中next_edge[v]++，可以让看过的出边，就不再看了
  for (int i = now[a]; i > 0; i = e[i].nex) {
    now[a] = i;
    int b = e[i].to;
    // 如果节点 e.to 的层次不等于当前节点的层次加1,或者边的流量等于容量,则跳过
    if (level[b] != level[a] + 1 || e[i].flow == e[i].weight) {
      continue;
    }
    // 递归寻找增广路径,正向增流，反向减流
    int f = dfs(b, min(flow, e[i].weight - e[i].flow), t);
    if (f) {
      e[i].flow += f;
      e[i ^ 1].flow -= f;
      return f;
    } else {
      // 增广完毕的点，剪枝
      level[b] = 0;
    }
  }
  return 0;
}

// Dinic算法主函数,用于计算最大流
long long max_flow(int s, int t) {
  long long total_flow = 0;
  while (bfs(s, t)) {
    int f;
    while ((f = dfs(s, INT_MAX, t)) > 0) {
      total_flow += f;
    }
  }
  return total_flow;
}

vector<int> path;

// 寻找一条从源点到汇点的路径
void find_path(int v) {
  path.push_back(v);
  // 弧优化，寻找这条路径时，next_edge[v]++，可以让看过的出边，就不再看了，或者用过的出边就不再用了
  for (int i = now[v]; i > 0; i = e[i].nex) {
    now[v] = i;
    if (e[i].flow > 0) {
      now[v] = e[i].nex;
      find_path(e[i].to);
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s, t;
  // 读入房间数 n 和传送门数 m
  cin >> n >> m;
  // 链式前向星为了用奇偶边技巧需要从 2 开始，所以前两个位置空着
  e.resize(2 * m + 2);
  head.resize(n + 1);
  level.resize(n + 1);
  next_edge.resize(n + 1);
  now.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    addEdge(a, b, 1);
    addEdge(b, a, 0);
  }
  s = 1;
  t = n;

  // 输出最大流,即最多可以玩的天数
  cout << max_flow(s, t) << "\n";

  for (int i = 1; i <= n; i++)
    now[i] = head[i];
  // 对于每一条从源点出发的边,如果流量大于0,则找出对应的路径并输出
  for (int i = now[s]; i > 0; i = e[i].nex) {
    if (e[i].flow > 0) {
      path.clear();
      path.push_back(s);
      find_path(e[i].to);
      cout << path.size() << "\n";
      for (int v : path) {
        cout << v << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
