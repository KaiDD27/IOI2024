#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> result;

void grayCode(int n) {
  if (n == 1) {
    result[0] = "0";
    result[1] = "1";
    return;
  }
  grayCode(n - 1);
  for (int i = 0; i < (1 << (n - 1)); ++i) {
    result[(1 << n) - 1 - i] = "1" + result[i];
    result[i] = "0" + result[i];
  }
  return;
}

int main() {
  int n;
  cin >> n;
  result.resize(1 << n);
  grayCode(n);
  for (int i = 0; i < (1 << n); ++i) {
    cout << result[i] << endl;
  }
  return 0;
}