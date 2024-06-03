#include <array>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
// 默认排序优先级
const int DEPTH = 0;
const int BRANCH = 1;
const int IDX = 2;
const int PARENT = 3;
vector<array<int, 4>> nodes;
vector<vector<int>> adj;
set<int> stDeleted;
struct cmpNodes {
  bool operator()(int a, int b) const {
    if (nodes[a][DEPTH] == nodes[b][DEPTH]) {
      return a > b;
    } else {
      return nodes[a][DEPTH] > nodes[b][DEPTH];
    }
  }
};

vector<set<int, cmpNodes>> stNodesOfBranch;
set<int, cmpNodes> stDeepestInBranch;

void updateNode(array<int, 4> node) {
  auto [depth, branch, idx, parent] = node;
  nodes[idx] = node;
  stNodesOfBranch[branch].insert(idx);
  for (auto neighbour : adj[idx]) {
    if (neighbour != parent) {
      updateNode({depth + 1, branch, neighbour, idx});
    }
  }
}

void deleteNode(int cur) {
  stNodesOfBranch[nodes[cur][BRANCH]].erase(cur);
  stDeepestInBranch.erase(cur);
  stDeleted.insert(cur);

  for (auto neighbour : adj[cur]) {
    if (neighbour != nodes[cur][PARENT] &&
        stDeleted.find(neighbour) == stDeleted.end()) {
      deleteNode(neighbour);
    }
  }
}

int twoDeepest() {
  int answer = 0;
  auto it = stDeepestInBranch.begin();
  answer += nodes[*it][DEPTH];
  if (stDeepestInBranch.size() > 1) {
    it++;
    answer += nodes[*it][DEPTH];
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
    updateNode({1, branch, branch, 0});
    stDeepestInBranch.insert(*stNodesOfBranch[branch].begin());
  }

  cout << twoDeepest() + 1 << endl;

  for (int i = 0; i < m; i++) {
    cin >> k;
    deleteNode(k);
    if (!stNodesOfBranch[nodes[k][BRANCH]].empty()) {
      stDeepestInBranch.insert(*stNodesOfBranch[nodes[k][BRANCH]].begin());
    }
    cout << twoDeepest() + 1 << endl;
  }
}
