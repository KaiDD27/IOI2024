#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
queue<int> queChild;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    queChild.push(i);
  }
  while (!queChild.empty()) {
    queChild.push(queChild.front());
    queChild.pop();
    cout << queChild.front() << " ";
    queChild.pop();
  }
  return 0;
}