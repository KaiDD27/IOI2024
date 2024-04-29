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
  strS[strS.length() - 1] = '4';
  cout << strS << endl;
  return 0;
}