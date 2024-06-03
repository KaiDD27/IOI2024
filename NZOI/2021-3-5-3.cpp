#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

struct Node {
  int idx;
  int branch;
  int parent;
  int depth;
  // ！！！必须包含 idx 的判断，因为自定义的 struct没有默认排序规则了，
  bool operator<(const Node &other) const {
    if (depth == other.depth && branch == other.branch) {
      return idx > other.idx;
    } else if (depth == other.depth) {
      return branch > other.branch;
    } else {
      return depth > other.depth;
    }
  }
};
vector<Node> nodes;
vector<set<Node>> stNodesOfBranch;
set<Node> stDeepestInBranch;
vector<vector<int>> adj;
set<int> stDeleted;

void updateNode(int branch, int cur, int parent, int depth) {
  nodes[cur].idx = cur;
  nodes[cur].branch = branch;
  nodes[cur].parent = parent;
  nodes[cur].depth = depth;
  stNodesOfBranch[branch].insert(nodes[cur]);
  for (auto neighbour : adj[cur]) {
    if (neighbour != parent) {
      updateNode(branch, neighbour, cur, depth + 1);
    }
  }
}

void deleteNode(int cur) {
  stNodesOfBranch[nodes[cur].branch].erase(nodes[cur]);
  stDeepestInBranch.erase(nodes[cur]);
  stDeleted.insert(cur);

  for (auto neighbour : adj[cur]) {
    if (neighbour != nodes[cur].parent &&
        stDeleted.find(neighbour) == stDeleted.end()) {
      deleteNode(neighbour);
    }
  }
}

int twoDeepest() {
  int answer = 0;
  auto it = stDeepestInBranch.begin();
  answer += it->depth;
  it++;
  if (it != stDeepestInBranch.end()) {
    answer += it->depth;
  }
  return answer;
}

int main() {
  int n, m, a, b, k;
  cin >> n >> m;
  adj.resize(n); // Resize the vector to accommodate n nodes
  stNodesOfBranch.resize(n);
  nodes.resize(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (auto branch : adj[0]) {
    updateNode(branch, branch, 0, 1);
    stDeepestInBranch.insert(*stNodesOfBranch[branch].begin());
  }

  cout << twoDeepest() + 1 << endl;

  for (int i = 0; i < m; i++) {
    cin >> k;
    deleteNode(k);
    if (stNodesOfBranch[nodes[k].branch].begin() !=
        stNodesOfBranch[nodes[k].branch].end()) {
      stDeepestInBranch.insert(*stNodesOfBranch[nodes[k].branch].begin());
    }
    cout << twoDeepest() + 1 << endl;
  }
}
