#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
string strS;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> strS;
  char currC = 'A';
  ll minStroke = 0;
  for (auto c : strS) {
    minStroke +=
        (abs(c - currC) <= 26 - abs(c - currC) ? abs(c - currC)
                                               : (26 - abs(c - currC)));
    currC = c;
    minStroke++;
  }
  cout << minStroke << endl;
  return 0;
}