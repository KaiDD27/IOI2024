#include <array>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<bool> cOfficial;
vector<tuple<char, ll>> queryM;
vector<ll> cRank;
map<ll, ll> mpOffical;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, m;
  cin >> n >> m;
  cOfficial.resize(n + 1, true);
  cRank.resize(n + 1, 0);
  queryM.resize(m);
  for (auto &[chM, idx] : queryM) {
    cin >> chM >> idx;
    if (chM == 'o')
      mpOffical[idx] = idx;
  }
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      cOfficial[idx] = !cOfficial[idx];
      if (cOfficial[idx] == false) {
        mpOffical.erase(idx);
        auto it = mpOffical.upper_bound(idx);
        while (it != mpOffical.end()) {
          it->second--;
        }
      } else {
      }
    }
    if (chM == 'o') {
      if (cOfficial[idx] == false)
        cout << "UNOFFICIAL" << endl;
      else {
        ll rank = 0;
        for (int i = 1; i <= idx; i++) {
          rank += cOfficial[i];
        }
        cout << rank << endl;
      }
    }
  }

  return 0;
}