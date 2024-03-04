#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;
using ll = long long;
#define endl '\n'
multiset<int> mSetA, mSetB;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m, k;
  int ans = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mSetA.insert(a);
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    mSetB.insert(b);
  }
  for (auto itA = mSetA.begin(), itB = mSetB.begin();
       itA != mSetA.end() && itB != mSetB.end();) {
    if (abs(*itA - *itB) <= k) {
      ans++;
      itA++;
      itB++;
    } else if (*itB > *itA) {
      itA++;
    } else if (*itA > *itB) {
      itB++;
    }
  }
  cout << ans << endl;
  return 0;
}