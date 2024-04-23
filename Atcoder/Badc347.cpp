#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
set<string> setString;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strS;
  cin >> strS;
  int len = strS.length();
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      string subString = strS.substr(i, j - i + 1);
      setString.insert(subString);
    }
  }
  cout << setString.size() << endl;
  return 0;
}