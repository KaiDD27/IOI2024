#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<char, int> mpType;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together

  while (true) {
    char charIn;
    cin >> charIn;
    if (charIn == 'D')
      break;
    int ni;
    cin >> ni;
    mpType[charIn] += ni;
  }
  cout << mpType['G'] << " " << mpType['C'] << " " << mpType['E'] << " "
       << mpType['P'] << " " << mpType['L'] << " " << mpType['S'] << endl;

  return 0;
}