#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
void generateGrayCode(vector<string> &grayCode, int n) {
  if (n == 1) {
    grayCode.push_back("0");
    grayCode.push_back("1");
    return;
  }
  generateGrayCode(grayCode, n - 1);
  int halfCnt = (int)pow(2, n - 1);
  for (int i = halfCnt - 1; i >= 0; i--) {
    grayCode.push_back("1" + grayCode[i]);
    grayCode[i] = "0" + grayCode[i];
  }
}
int main() {
  int n;
  cin >> n;
  vector<string> grayCode;
  generateGrayCode(grayCode, n);
  for (int i = 0; i < (int)pow(2, n); i++)
    cout << grayCode[i] << endl;
  return 0;
}