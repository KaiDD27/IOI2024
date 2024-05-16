#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> elevationChange;
ll mxChange = 0;
ll change = 0;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  elevationChange.resize(n);
  for (auto &ei : elevationChange) {
    cin >> ei;
    if (ei > 0)
      change += ei;
    else {
      mxChange = max(mxChange, change);
      change = 0;
    }
  }
  if (mxChange == 0 && change > 0)
    mxChange = change;
  if (mxChange > 0)
    cout << mxChange << endl;
  else
    cout << -1 << endl;
  return 0;
}