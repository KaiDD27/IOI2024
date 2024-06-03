#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> adj;
unordered_set<int> stDeleted;
vector<int> branchOfNode;
vector<int> parentOfNode;
vector<int> depthOfNode;

// Compare nodes by their depths.
// Extra condition when depths equal is to guarantee uniqueness within sets
struct CmpNodes {
  bool operator()(int a, int b) const {
    if (depthOfNode[a] == depthOfNode[b]) {
      return a > b;
    } else {
      return depthOfNode[a] > depthOfNode[b];
    }
  }
};

vector<set<int, CmpNodes>> stNodesOfBranch;
set<int, CmpNodes> stDeepestInBranch;

void updateNode(int branch, int cur, int parent, int depth) {
  branchOfNode[cur] = branch;
  parentOfNode[cur] = parent;
  depthOfNode[cur] = depth;
  stNodesOfBranch[branch].insert(cur);
  for (auto neighbour : adj[cur]) {
    if (neighbour != parent) {
      updateNode(branch, neighbour, cur, depth + 1);
    }
  }
}

void deleteNode(int cur) {
  stNodesOfBranch[branchOfNode[cur]].erase(cur);
  stDeepestInBranch.erase(cur);
  stDeleted.insert(cur);

  for (auto neighbour : adj[cur]) {
    if (neighbour != parentOfNode[cur] &&
        stDeleted.find(neighbour) == stDeleted.end()) {
      deleteNode(neighbour);
    }
  }
}

int twoDeepest() {
  int answer = 0;
  auto deepest = stDeepestInBranch.begin();
  answer += depthOfNode[*deepest];
  deepest++;
  if (deepest != stDeepestInBranch.end()) {
    answer += depthOfNode[*deepest];
  }
  return answer;
}

int main() {
  int n, m, a, b, k;
  cin >> n >> m;

  adj.resize(n + 1); // Resize the vector to accommodate n nodes

  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  branchOfNode.resize(n + 1);    // Resize the vector to accommodate n nodes
  parentOfNode.resize(n + 1);    // Resize the vector to accommodate n nodes
  depthOfNode.resize(n + 1);     // Resize the vector to accommodate n nodes
  stNodesOfBranch.resize(n + 1); // Resize the vector to accommodate n nodes

  for (auto branch : adj[0]) {
    updateNode(branch, branch, 0, 1);
    stDeepestInBranch.insert(*stNodesOfBranch[branch].begin());
  }

  cout << twoDeepest() + 1 << endl;

  for (int i = 0; i < m; i++) {
    cin >> k;
    deleteNode(k);
    if (stNodesOfBranch[branchOfNode[k]].begin() !=
        stNodesOfBranch[branchOfNode[k]].end()) {
      stDeepestInBranch.insert(*stNodesOfBranch[branchOfNode[k]].begin());
    }
    cout << twoDeepest() + 1 << endl;
  }
}
