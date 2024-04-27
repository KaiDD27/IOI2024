#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> abc(26);

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strS;
  cin >> strS;
  ll ans = 0;
  ll len = strS.length();
  for (ll i = 0; i < len; i++) {
    abc[strS[i] - 'a']++;
  }

  for (ll i = 0; i < len; i++) {
    ans = ans + len - abc[strS[i] - 'a'];
  }
  ans = ans / 2;
  for (int i = 0; i < 26; i++) {
    if (abc[i] > 1) {
      ans++;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}