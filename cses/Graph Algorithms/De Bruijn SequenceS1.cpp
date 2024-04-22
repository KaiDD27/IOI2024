// 有向图欧拉回路
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<stack<int>> vertex;
vector<int> deBruijnSequence;
void dfs(int node) {
  while (!vertex[node].empty()) {
    int nex = vertex[node].top();
    vertex[node].pop();
    dfs(nex);
    deBruijnSequence.push_back(node & 1);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  if (n == 1) {
    cout << "01";
    return 0;
  }
  vertex.resize(1 << (n - 1));
  for (int i = 0; i < 1 << (n - 1); i++) {
    vertex[i].push((i << 1) & (~(1 << (n - 1))));
    vertex[i].push(((i << 1) + 1) & (~(1 << (n - 1))));
  }
  dfs(0);
  for (int i = 0; i < n - 1; i++)
    deBruijnSequence.push_back(0);
  reverse(deBruijnSequence.begin(), deBruijnSequence.end());
  for (auto d : deBruijnSequence)
    cout << d;
  cout << endl;
  return 0;
}