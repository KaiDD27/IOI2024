#include <cstddef>
#include <iostream>
#include <stack>

using namespace std;
using ll = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  stack<pair<int, int>> numStack; // 升序单调栈，序号越小，则值越小，否则无价值
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    pair<int, int> num;
    cin >> num.first;
    num.second = i;
    while (!numStack.empty() && numStack.top().first >= num.first)
      numStack.pop();
    if (!numStack.empty())
      cout << numStack.top().second << " ";
    else
      cout << 0 << " ";
    numStack.push(num);
  }
  return 0;
}