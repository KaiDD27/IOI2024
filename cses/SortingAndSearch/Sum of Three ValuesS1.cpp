#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, ll>> a; // first是值，second 是 position
vector<array<ll, 3>> sumOfTwo;
map<ll, ll> mpSumToIdx;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, x;
  cin >> n >> x;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  // 尺取法，属于贪心策略，这题是求两个数之和的升级版
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n - 2; i++) {
    int l = i + 1, r = n;
    while (l < r) {
      if (a[l].first + a[r].first == x - a[i].first) {
        cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
        return 0;
      } else if (a[l].first + a[r].first < x - a[i].first)
        l++;
      else
        r--;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}