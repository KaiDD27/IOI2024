#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define endl "\n"
set<ll> seta;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, k;
  cin >> n >> k;
  ll sum = k * (k + 1) / 2;
  for (int i = 0; i < n; i++) {
    ll ai;
    cin >> ai;
    if (ai <= k) {
      seta.insert(ai);
    }
  }
  for (auto ai : seta) {
    sum -= ai;
  }
  cout << sum << endl;
  return 0;
}