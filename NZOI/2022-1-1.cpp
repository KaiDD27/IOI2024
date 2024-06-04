#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
string strColor = "RGB";
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  string strN;
  cin >> strN;
  strN = 'S' + strN + 'E';
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (strN[i] == strN[i - 1]) {
      for (int m = 0; m < 3; m++) {
        if (strColor[m] != strN[i - 1] && strColor[m] != strN[i + 1]) {
          strN[i] = strColor[m];
        }
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}