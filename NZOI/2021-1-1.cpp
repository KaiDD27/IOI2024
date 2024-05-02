#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int color[4];
string colorString[4] = {"Red", "Pink", "Purple", "Blue"};
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  for (int i = 0; i < 7; i++) {
    string strColor;
    cin >> strColor;
    switch (strColor[1]) {
    case 'e':
      color[0]++;
      break;
    case 'i':
      color[1]++;
      break;
    case 'u':
      color[2]++;
      break;
    case 'l':
      color[3]++;
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (color[i] < 2) {
      cout << colorString[i] << endl;
    }
  }
  return 0;
}