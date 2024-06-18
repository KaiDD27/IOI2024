#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll t;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> t;
  for (int i = 0; i < t; i++) {
    string strS;
    cin >> strS;
    if (*strS.rbegin() == '0')
      cout << "E";
    else
      cout << "B";
    cout << endl;
  }
  return 0;
}