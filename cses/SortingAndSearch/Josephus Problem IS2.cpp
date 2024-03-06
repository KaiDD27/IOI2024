#include <iostream>
#include <list>
#include <numeric>

using namespace std;
using ll = long long;
list<int> lstChild;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  lstChild.resize(n);
  iota(lstChild.begin(), lstChild.end(), 1); // initial from 1 to n
  auto it = lstChild.begin();
  while (!lstChild.empty()) {
    if (it == lstChild.end())
      it = lstChild.begin();
    it++;
    if (it == lstChild.end())
      it = lstChild.begin();
    cout << *it << " ";
    auto itToDel = it;
    it++;
    lstChild.erase(itToDel);
  }
  return 0;
}