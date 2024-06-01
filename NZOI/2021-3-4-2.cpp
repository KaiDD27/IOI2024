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
    stOfficialIntervalSum.insert(idx);
  }
  bitTree.resize(stOfficialIntervalSum.size() + 1, 0);
  int iTree = 1, prevSi = 0;
  for (auto si : stOfficialIntervalSum) {
    update(iTree, si - prevSi);
    prevSi = si;
    mpIdxToBitTree[si] = iTree;
    iTree++;
  }
  mpIdxToBitTree[0] = 0;
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      if ((query(mpIdxToBitTree[idx]) - query(mpIdxToBitTree[idx] - 1)) ==
          (idx - prev(mpIdxToBitTree.find(idx))->first))
        update(mpIdxToBitTree[idx], -1);
      else
        update(mpIdxToBitTree[idx], 1);
    }
    if (chM == 'o') {
      if ((query(mpIdxToBitTree[idx]) - query(mpIdxToBitTree[idx] - 1)) !=
          (idx - prev(mpIdxToBitTree.find(idx))->first))
        cout << "UNOFFICIAL" << endl;
      else {
        cout << query(mpIdxToBitTree[idx]) << endl;
      }
    }
  }
  return 0;
}