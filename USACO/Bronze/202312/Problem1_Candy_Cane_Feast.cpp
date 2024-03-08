#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> n;
vector<pair<ll, ll>> m;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int N, M;
  cin >> N >> M;
  n.resize(N);
  m.resize(M);
  for (auto &ni : n)
    cin >> ni;
  for (auto &mi : m) {
    mi.first = 0;
    cin >> mi.second;
  }
  for (auto &mi : m) {
    for (auto &ni : n) {
      if (mi.first == mi.second)
        break;
      if (ni > mi.first) {
        ll preNi = ni;
        if (ni >= mi.second) {
          ni += (mi.second - mi.first);
          mi.first = mi.second;
        } else {
          ni += (ni - mi.first);
          mi.first = preNi;
        }
      }
    }
  }
  for (auto ni : n)
    cout << ni << endl;
  return 0;
}