#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
set<ll> setSkills;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll si;
    cin >> si;
    setSkills.insert(si);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll rivalSkill;
    cin >> rivalSkill;
    auto it = setSkills.lower_bound(rivalSkill);
    if (it != setSkills.end()) {
      setSkills.erase(it);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}