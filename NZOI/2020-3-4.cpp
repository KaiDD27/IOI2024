#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  string strN = '0' + to_string(n);

  bool flagBigger = false;
  for (int i = 1; i < strN.length(); i++) {
    if (flagBigger == false) {
      if (strN[i - 1] == strN[i] && strN[i] == '9') {
        int j = i;
        while (j > 0) {
          // 不可能是 9，所以可以大胆+1
          if (strN[j - 1] == strN[j] && strN[j] == '9') {
            strN[j - 2] += 1;
            strN[j - 1] = '0';
            strN[j] = '1';
            j -= 2;
          } else {
            break;
          }
        }
        flagBigger = true;
      } else if (strN[i - 1] == strN[i]) {
        strN[i] += 1;
        flagBigger = true;
      }
    } else { // 尽可能小
      if (strN[i - 1] != '0') {
        strN[i] = '0';
      } else {
        strN[i] = '1';
      }
    }
  }
  if (strN[0] == '1')
    cout << strN << endl;
  else
    cout << strN.substr(1, strN.length() - 1) << endl;
  return 0;
}