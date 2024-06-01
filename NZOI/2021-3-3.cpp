#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> cOfficial, w;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, m;
  cin >> n;
  cOfficial.resize(n);
  for (auto &ci : cOfficial)
    cin >> ci;
  cin >> m;
  w.resize(m);
  for (auto &wi : w)
    cin >> wi;
  sort(cOfficial.begin(), cOfficial.end());
  sort(w.begin(), w.end());
  ll maxMoney = 0;
  for (int i = n - 1, j = m - 1; i >= 0; i--) {
    while (j >= 0) {
      if (cOfficial[i] >= w[j]) {
        maxMoney += w[j];
        j--;
        break;
      }
      j--;
    }
    if (j < 0)
      break;
  }
  cout << maxMoney << endl;
  return 0;
}