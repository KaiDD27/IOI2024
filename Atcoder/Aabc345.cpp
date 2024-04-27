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
  if (strS[0] != '<') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < strS.size() - 1; i++) {
    if (strS[i] != '=') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (strS[strS.size() - 1] != '>') {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}