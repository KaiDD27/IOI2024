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
  int flag = 0;
  for (auto si : strS) {
    if (si == '|') {
      flag = (flag + 1) % 2;
      continue;
    }
    if (flag == 0)
      cout << si;
  }
  return 0;
}