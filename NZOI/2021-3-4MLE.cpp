#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<tuple<char, ll>> queryM;
vector<bool> official;
vector<int> bitTree;
set<ll> stNoOfficial;
void update(int i, int val, int n) {
  while (i <= n) {
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
  official.resize(n + 1, true);
  bitTree.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    update(i, 1, n);
  }
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      official[idx] = !official[idx];
      if (official[idx] == true)
        update(idx, 1, n);
      else
        update(idx, -1, n);
    }
    if (chM == 'o') {
      if (official[idx] == false)
        cout << "UNOFFICIAL" << endl;
      else {
        cout << query(idx) << endl;
      }
    }
  }
  return 0;
}