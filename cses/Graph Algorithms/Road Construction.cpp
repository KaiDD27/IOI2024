// Kruskal算法
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> link;
vector<int> sizeComponent;
int findSet(int a) {
  if (link[a] == a)
    return a;
  return link[a] = findSet(link[a]);
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  link.resize(n + 1);
  sizeComponent.resize(n + 1, 1);
  int maxSize = 1;
  int numComponent = n;
  for (int i = 1; i <= n; i++) {
    link[i] = i;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    int e1 = findSet(a);
    int e2 = findSet(b);
    if (e1 != e2) {
      link[e2] = e1;
      sizeComponent[e1] += sizeComponent[e2];
      sizeComponent[e2] = 0;
      maxSize = max(maxSize, sizeComponent[e1]);
      numComponent--;
    }
    cout << numComponent << " " << maxSize << endl;
  }
  return 0;
}