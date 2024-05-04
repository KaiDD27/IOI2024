#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strS;
  cin >> strS;

  if (strS[0] != 'A' && strS[0] != 'B' && strS[0] != 'C') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < strS.length(); i++) {
    if (((strS[i] != strS[i - 1]) && (strS[i] != (strS[i - 1] + 1))) &&
        (strS[i] != (strS[i - 1] + 2))) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
