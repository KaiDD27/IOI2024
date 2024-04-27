// Dinic算法
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, index, flow, capacity;
};

vector<vector<Edge>> graph;
vector<int> level, next_edge;

// 广度优先搜索,用于计算节点的层次
bool bfs(int s, int t) {
  fill(level.begin(), level.end(), -1);
  queue<int> q;
  q.push(s);
  level[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (const auto &e : graph[v]) {
      // 如果节点 e.to 未访问过且边的流量小于容量,则将其加入队列
      if (level[e.to] == -1 && e.flow < e.capacity) {
        q.push(e.to);
        level[e.to] = level[v] + 1;
      }
    }
  }
  // 如果汇点的层次不小于0,说明存在增广路径
  return level[t] >= 0;
}

// 深度优先搜索,用于寻找增广路径并更新正向反向流
int dfs(int v, int flow, int t) {
  if (v == t) {
    return flow;
  }
  // 弧优化，在这一条dfs
  // 寻找增广路径的过程中next_edge[v]++，可以让看过的出边，就不再看了
  for (; next_edge[v] < graph[v].size(); next_edge[v]++) {
    auto &e = graph[v][next_edge[v]];
    // 如果节点 e.to 的层次不等于当前节点的层次加1,或者边的流量等于容量,则跳过
    if (level[e.to] != level[v] + 1 || e.flow == e.capacity) {
      continue;
    }
    // 递归寻找增广路径,正向增流，反向减流
    int f = dfs(e.to, min(flow, e.capacity - e.flow), t);
    if (f) {
      e.flow += f;
      graph[e.to][e.index].flow -= f;
      return f;
    } else {
      // 增广完毕的点，剪枝
      level[e.to] = 0;
    }
  }
  return 0;
}

// Dinic算法主函数,用于计算最大流
long long max_flow(int s, int t) {
  long long total_flow = 0;
  while (bfs(s, t)) {
    int f;
    fill(next_edge.begin(), next_edge.end(), 0);
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
  for (; next_edge[v] < graph[v].size(); next_edge[v]++) {
    auto &e = graph[v][next_edge[v]];
    if (e.flow > 0) {
      next_edge[v]++;
      find_path(e.to);
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
  graph.resize(n + 1);
  level.resize(n + 1);
  next_edge.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int c = 1;
    int d = graph[a].size();
    int e = graph[b].size();
    // 添加正向边和反向边
    graph[a].push_back({b, e, 0, c});
    graph[b].push_back({a, d, 0, 0});
  }
  s = 1;
  t = n;

  // 输出最大流,即最多可以玩的天数
  cout << max_flow(s, t) << "\n";

  fill(next_edge.begin(), next_edge.end(), 0);
  // 对于每一条从源点出发的边,如果流量大于0,则找出对应的路径并输出
  for (const auto &e : graph[s]) {
    if (e.flow > 0) {
      path.clear();
      path.push_back(s);
      find_path(e.to);
      cout << path.size() << "\n";
      for (int v : path) {
        cout << v << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
