#include <algorithm>
#include <array>
#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n, x, m;
vector<int> k;
vector<array<int, 3>> hdi;

set<vector<int>> stK;
map<int, int> mpItH, mpHtI;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> x >> m;
  k.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> k[i];
  hdi.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> hdi[i][0] >> hdi[i][1];
    hdi[i][2] = i;
  }
  sort(hdi.begin(), hdi.end());

  vector<int> successPath;
  stack<tuple<vector<int>, int, vector<int>>> sk;
  sk.push({k, 0, {}});
  while (!sk.empty()) {
    auto [ak, currP, path] = sk.top();
    sk.pop();
    // m是最后一个 programmer 的下一个，也就是说所有的程序员都已经安全转移了
    if (currP == m) {
      successPath = path;
      break;
    }

    if (stK.count(ak))
      continue;
    stK.insert(ak);

    for (int i = ((hdi[currP][0] - hdi[currP][1] / x) > 1
                      ? (hdi[currP][0] - hdi[currP][1] / x)
                      : 1);
         i <= n && (i <= (hdi[currP][0] + hdi[currP][1] / x)); i++) {
      if (ak[i] == 0)
        continue;
      vector<int> bk = ak;
      --bk[i];
      if (stK.count(bk))
        continue;
      vector<int> nextPath = path;
      int nextP = currP;
      nextPath.push_back(i);
      sk.push({bk, ++nextP, nextPath});
    }
  }
  if (successPath.size() != m)
    cout << "SOLUTION IS NON-TRIVIAL" << endl;
  else {
    cout << "SOLUTION IS TRIVIAL" << endl;
    vector<int> path(successPath.size());
    for (int i = 0; i < m; i++) {
      path[hdi[i][2]] = successPath[i];
    }
    for (auto pi : path)
      cout << pi << endl;
  }

  return 0;
}