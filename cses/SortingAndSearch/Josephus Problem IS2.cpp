#include <iostream>
#include <list>
#include <numeric>

using namespace std;
using ll = long long;
enum { endl = '\n' };

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  list<int> childList(n);
  iota(childList.begin(), childList.end(), 1); // initial from 1 to n
  auto it = childList.begin();
  while (!childList.empty()) {
    if (it == childList.end())
      it = childList.begin();
    it++;
    if (it == childList.end())
      it = childList.begin();
    cout << *it << " ";
    auto itToDel = it;
    it++;
    childList.erase(itToDel);
  }
  return 0;
}