#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
stack<int> sk;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int a = 1;
  while (a) {
    cin >> a;
    sk.push(a);
  }
  while (!sk.empty()) {
    cout << sk.top() << endl;
    sk.pop();
  }
  return 0;
}