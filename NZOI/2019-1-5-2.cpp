#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const int MOD = 10000;
ll a, b, c, d, n;
typedef vector<vector<ll>> Matrix;
vector<Matrix> dp(35, Matrix(2, vector<ll>(2)));

Matrix multiply(Matrix &m1, Matrix &m2) {
  int size = m1.size();
  Matrix res(size, vector<ll>(size, 0));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
        res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % MOD;
      }
    }
  }
  return res;
}

void initialDP() {
  dp[0] = {{a, b}, {c, d}};
  for (int i = 1; i < 35; i++) {
    dp[i] = multiply(dp[i - 1], dp[i - 1]);
  }
}

int main() {
  cin >> a >> b >> c >> d >> n;
  initialDP();
  Matrix ans = {{1, 0}, {0, 1}};
  // 二进制一位位相乘
  for (int i = 0; n > 0; i++) {
    if (n & 1) {
      ans = multiply(ans, dp[i]);
    }
    n >>= 1;
  }
  cout << (ans[0][0] + ans[0][1]) % MOD << " " << (ans[1][0] + ans[1][1]) % MOD
       << endl;
  return 0;
}