#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strS, strT;
  cin >> strS >> strT;
  for (int si = 0, ti = 0; si < strS.length();) {
    if (strS[si] == strT[ti]) {
      cout << ti + 1 << " ";
      si++;
      ti++;
    } else
      ti++;
  }
  cout << endl;
  return 0;
}