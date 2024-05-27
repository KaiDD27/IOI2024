#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
set<char> setFirstChar;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strFirst;
  cin >> strFirst;
  for (auto si : strFirst) {
    setFirstChar.insert(si);
  }
  if (setFirstChar.size() != strFirst.length()) {
    for (int i = 0; i < 4; i++) {
      string strColor;
      cin >> strColor;
      if (strColor.length() % 2 == 0) {
        cout << "bad" << endl;
        return 0;
      }
    }
    cout << "best" << endl;
  } else {
    vector<string> strColors(4);
    cin >> strColors[0];
    for (int i = 1; i < 4; i++) {
      cin >> strColors[i];
      if (strColors[i].length() >= strColors[i - 1].length()) {
        cout << "bad" << endl;
        return 0;
      }
    }
    cout << "ok" << endl;
  }
  return 0;
}