#include <iostream>
#include <set>

using namespace std;
using ll = long long;
set<int> setChild;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    setChild.insert(i);
  }
  auto it = setChild.begin();
  while (!setChild.empty()) {
    if (it == setChild.end())
      it = setChild.begin();
    it++;
    if (it == setChild.end())
      it = setChild.begin();
    cout << *it << " ";
    auto itToDel = it;
    it++;
    setChild.erase(itToDel);
  }
  return 0;
}