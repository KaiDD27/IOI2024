#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string strN;
  cin >> strN;
  long long value, j, total = 0, len = strN.length();
  for (int i = 0; i < len; i++) {
    value = strN[i] - '0';
    j = len - i - 1;
    if (j > 0)
      total += value * j * pow(10, j - 1);
    if (value == 3) {
      total += 1;
      if (i + 1 < len)
        total += stoll(strN.substr(i + 1));
    } else if (value > 3) {
      total += pow(10, j);
    }
  }
  cout << total << endl;
}
