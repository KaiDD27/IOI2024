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
vector<set<array<int, 4>>> stNodesOfBranch;
set<array<int, 4>> stDeepestInBranch;
vector<vector<int>> adj;
set<int> stDeleted;

void updateNode(array<int, 4> node) {
  auto [depth, branch, idx, parent] = node;
  nodes[idx] = node;
  stNodesOfBranch[branch].insert(node);
  for (auto neighbour : adj[idx]) {
    if (neighbour != parent) {
      updateNode({depth + 1, branch, neighbour, idx});
    }
  }
}

void deleteNode(int cur) {
  stNodesOfBranch[nodes[cur][BRANCH]].erase(nodes[cur]);
  stDeepestInBranch.erase(nodes[cur]);
  stDeleted.insert(cur);
  // 以curr 为根的子树全部删除
  for (auto neighbour : adj[cur]) {
    if (neighbour != nodes[cur][PARENT] &&
        stDeleted.find(neighbour) == stDeleted.end()) {
      deleteNode(neighbour);
    }
  }
}

int twoDeepest() {
  int answer = 0;
  auto it = stDeepestInBranch.rbegin();
  answer += it->at(DEPTH);
  if (stDeepestInBranch.size() > 1) {
    it++;
    answer += it->at(DEPTH);
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
    stDeepestInBranch.insert(*stNodesOfBranch[branch].rbegin());
  }

  cout << twoDeepest() + 1 << endl;

  for (int i = 0; i < m; i++) {
    cin >> k;
    deleteNode(k);
    if (!stNodesOfBranch[nodes[k][BRANCH]].empty()) {
      stDeepestInBranch.insert(*stNodesOfBranch[nodes[k][BRANCH]].rbegin());
    }
    cout << twoDeepest() + 1 << endl;
  }
}
