#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<char, ll>> queryM;
vector<bool> mpOfficial;
vector<int> bitTree;
set<ll> stNoOfficial;
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
  }
  mpOfficial.resize(n + 1, true);
  bitTree.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    update(i, 1);
  }
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      mpOfficial[idx] = !mpOfficial[idx];
      if (mpOfficial[idx] == true)
        update(idx, 1);
      else
        update(idx, -1);
    }
    if (chM == 'o') {
      if (mpOfficial[idx] == false)
        cout << "UNOFFICIAL" << endl;
      else {
        cout << query(idx) << endl;
      }
    }
  }
  return 0;
}