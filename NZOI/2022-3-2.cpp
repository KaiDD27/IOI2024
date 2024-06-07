#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, m, va, vb;
vector<string> dependencyAName, dependencyBName;
vector<map<string, ll>> dependencyMpA, dependencyMpB;
set<string> stDependencySame;
set<vector<ll>> stB;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m >> va >> vb;
  dependencyAName.resize(n);
  dependencyMpA.resize(va);
  for (int i = 0; i < n; i++) {
    cin >> dependencyAName[i];
  }
  for (int vi = 0; vi < va; vi++) {
    for (int i = 0; i < n; i++)
      cin >> dependencyMpA[vi][dependencyAName[i]];
  }
  dependencyBName.resize(m);
  dependencyMpB.resize(vb);
  for (int i = 0; i < m; i++) {
    cin >> dependencyBName[i];
    for (int j = 0; j < n; j++) {
      if (dependencyAName[j] == dependencyBName[i]) {
        stDependencySame.insert(dependencyAName[j]);
        break;
      }
    }
  }
  for (int vi = 0; vi < vb; vi++) {
    for (int i = 0; i < m; i++)
      cin >> dependencyMpB[vi][dependencyBName[i]];
  }

  for (int vi = 0; vi < vb; vi++) {
    vector<ll> tmp;
    for (auto si : stDependencySame)
      tmp.push_back(dependencyMpB[vi][si]);
    tmp.push_back(vi);
    stB.insert(tmp);
  }
  for (int vi = va - 1; vi >= 0; vi--) {
    vector<ll> tmp;
    for (auto si : stDependencySame)
      tmp.push_back(dependencyMpA[vi][si]);
    // vb-1是最大的版本号
    tmp.push_back(vb);
    auto it = stB.upper_bound(tmp);
    if (it == stB.begin())
      continue;
    it--;
    bool flagSame = true;
    for (int i = 0; i < tmp.size() - 1; i++) {
      if (tmp[i] != (*it)[i]) {
        flagSame = false;
        break;
      }
    }
    if (flagSame == true) {
      cout << vi << " " << (*it)[(*it).size() - 1] << endl;
      return 0;
    }
  }
  return 0;
}