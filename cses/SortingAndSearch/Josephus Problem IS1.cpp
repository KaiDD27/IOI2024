#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
enum { endl = '\n' };

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  queue<int> childQue;
  for (int i = 1; i <= n; i++) {
    childQue.push(i);
  }
  while (!childQue.empty()) {
    childQue.push(childQue.front());
    childQue.pop();
    cout << childQue.front() << " ";
    childQue.pop();
  }
  return 0;
}