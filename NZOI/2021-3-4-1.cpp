#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<char, ll>> queryM;
set<int> stOfficialIntervalSum;
vector<int> bitTree;
map<int, bool> mpOfficial;
map<int, int> mpIdxToBitTree;
void update(int i, int val) {
  while (i < bitTree.size()) {
    bitTree[i] += val;
    i += i & (-i);
  }
}
int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += bitTree[i];
    i -= i & (-i);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, m;
  cin >> n >> m;
  queryM.resize(m);
  for (auto &[chM, idx] : queryM) {
    cin >> chM >> idx;
    if (chM == 'o')
      stOfficialIntervalSum.insert(idx);
    else if (chM == 't')
      mpOfficial[idx] = true;
  }

  bitTree.resize(stOfficialIntervalSum.size() + 1, 0);
  int iTree = 1, prevSi = 0;
  for (auto si : stOfficialIntervalSum) {
    update(iTree, si - prevSi);
    prevSi = si;
    mpIdxToBitTree[si] = iTree;
    iTree++;
  }
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      mpOfficial[idx] = !mpOfficial[idx];
      auto it = mpIdxToBitTree.lower_bound(idx);
      if (it != mpIdxToBitTree.end()) {
        if (mpOfficial[idx] == true)
          update(it->second, 1);
        else
          update(it->second, -1);
      }
    }
    if (chM == 'o') {
      if (mpOfficial.count(idx) && mpOfficial[idx] == false)
        cout << "UNOFFICIAL" << endl;
      else {
        cout << query(mpIdxToBitTree[idx]) << endl;
      }
    }
  }
  return 0;
}