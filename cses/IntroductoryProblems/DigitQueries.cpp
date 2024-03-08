#include <iostream>
#include <string>
#define ll long long
using namespace std;
// pow函数是一个通用的幂运算函数，它可以接受浮点数作为参数，并返回浮点数结果。
// 然而，浮点数的精度是有限的，当你用std::pow来计算大的整数时，可能会出现精度丢失的问题，
// 导致结果不准确。
long long pow10(int x) {
  long long result = 1;
  for (int i = 1; i <= x; i++) {
    result *= 10;
  }
  return result;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long k = 0;
    cin >> k;
    /*
     * Subtract k by sizes of groups until k becomes smaller than the size
     * of the current group. This produces the same effect as summing group
     * sizes until k becomes less than or equal to the sum.
     */
    long long n = 1;
    while (k > 9 * pow10(n - 1) * n) {
      k -= 9 * pow10(n - 1) * n;
      n++;
    }

    // k - 1 will equal j
    long long num = (k - 1) / n + pow10(n - 1);
    int pos = (int)((k - 1) % n);
    cout << to_string(num)[pos] << endl;
  }
  return 0;
}