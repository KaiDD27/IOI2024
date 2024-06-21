#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll t;
vector<vector<ll>> th;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> t;
  th.resize(t);
  for (int i = 0; i < t; i++) {
    ll n;
    cin >> n;
    th[i].resize(n - 1);
    for (auto &hii : th[i])
      cin >> hii;
  }
  for (auto h : th) {
    bool flagValid = true;
    ll n = h.size() + 1;
    vector<ll> num(n + 1);
    vector<ll> p(n);
    for (auto &hi : h) {
      num[hi]++;
      if ((hi != 1 && num[hi] > 1) || (hi == 1 && num[hi] > 2)) {
        flagValid = false;
        break;
      }
    }
    if (flagValid == false || h[n - 2] != 1) {
      cout << -1 << endl;
      continue;
    }
    // 1只出现一次,说明 1 只能出现在两头，则 1出现开头
    if (num[1] == 1) {
      ll tailNum;
      for (int i = 1; i <= n; i++)
        if (num[i] == 0)
          tailNum = i;
      p[0] = 1;
      p[n - 1] = tailNum;
      for (int pi = n - 2, hi = 0; pi > 0; pi--, hi++) {
        p[pi] = h[hi];
      }

    } else if (num[1] == 2) {
      ll headNum = 0, tailNum = 0;
      for (int i = 1; i <= n; i++)
        if (num[i] == 0 && headNum == 0)
          headNum = i;
        else if (num[i] == 0)
          tailNum = i;
      p[0] = headNum;
      p[n - 1] = tailNum;
      p[n - 2] = h[0];
      for (int hi = 1, pLeft = 0, pRight = n - 2; hi < n - 2; hi++) {
        if (p[pLeft] < p[pRight]) {
          pRight--;
          p[pRight] = h[hi];
        } else {
          pLeft++;
          p[pLeft] = h[hi];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << p[i];
      if (i != n - 1)
        cout << " ";
      else
        cout << endl;
    }
  }
  return 0;
}