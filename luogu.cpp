#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
string expand() {
  string strS;
  string strX;
  char chC;
  int d;
  while (cin >> chC) {
    if (chC == '[') {
      cin >> d;
      strX = expand();
      while (d--)
        strS += strX;
    } else if (chC == ']')
      return strS;
    else
      strS += chC;
  }
  return strS;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cout << expand();
  return 0;
}