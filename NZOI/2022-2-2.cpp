#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> s;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  s.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  sort(s.begin(), s.end());
  ll minTeam = 2001;
  ll maxTeam = 0;
  for (int i = 1; i <= n / 2; i++) {
    minTeam = min(minTeam, s[i] + s[n + 1 - i]);
    maxTeam = max(maxTeam, s[i] + s[n + 1 - i]);
  }
  cout << maxTeam - minTeam << endl;
  return 0;
}