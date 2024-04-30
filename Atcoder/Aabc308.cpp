#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> s;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int sa, sb, se;
  sa = 100;
  se = 675;
  for (int i = 0; i < 8; i++) {
    cin >> sb;
    if ((sb < sa) || (sb > se) || (sb % 25 != 0)) {
      cout << "No" << endl;
      return 0;
    }
    sa = sb;
  }
  cout << "Yes" << endl;
  return 0;
}