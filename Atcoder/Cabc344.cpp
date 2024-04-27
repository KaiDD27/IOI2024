#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> a, b, c, x;
set<ll> setSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m, l, q;
  cin >> n;
  a.resize(n);
  for (auto &ai : a)
    cin >> ai;
  cin >> m;
  b.resize(m);
  for (auto &bi : b)
    cin >> bi;
  cin >> l;
  c.resize(l);
  for (auto &ci : c)
    cin >> ci;
  cin >> q;
  x.resize(q);
  for (auto &xi : x)
    cin >> xi;

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      for (int l = 0; l < c.size(); l++)
        setSum.insert(a[i] + b[j] + c[l]);
    }
  }
  for (int i = 0; i < x.size(); i++) {
    if (setSum.count(x[i]))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}