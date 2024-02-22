#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
void generateGrayCode(vector<string> &grayCode, int n) {
  if (n == 0)
    return;
  generateGrayCode(grayCode, n - 1);
  int halfCnt = (int)pow(2, n - 1);
  for (int i = 0; i < halfCnt; i++) {
    grayCode[2 * halfCnt - 1 - i] = "1" + grayCode[i];
    grayCode[i] = "0" + grayCode[i];
  }
}
int main() {
  int n;
  cin >> n;
  vector<string> grayCode((int)pow(2, n));
  generateGrayCode(grayCode, n);
  for (int i = 0; i < (int)pow(2, n); i++)
    cout << grayCode[i] << endl;
  return 0;
}