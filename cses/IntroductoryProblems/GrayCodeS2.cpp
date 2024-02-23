#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<bitset<16>> result(1 << 16);

void grayCode(int n) {
  if (n == 1) {
    result[0] = bitset<16>(0);
    result[1] = bitset<16>(1);
  } else {
    grayCode(n - 1);
    for (int i = 0; i < (1 << (n - 1)); ++i) {
      result[(1 << n) - 1 - i] = result[i];
      result[(1 << n) - 1 - i].set(n - 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  grayCode(n);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = n - 1; j >= 0; --j) {
      cout << result[i][j];
    }
    cout << endl;
  }
  return 0;
}