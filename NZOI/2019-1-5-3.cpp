#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const int MOD = 10000;

typedef vector<vector<ll>> Matrix;

// Function to multiply two matrices
Matrix multiply(Matrix &A, Matrix &B) {
  int size = A.size();
  Matrix C(size, vector<ll>(size, 0));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}

// Function to perform matrix exponentiation
Matrix matrixExpo(Matrix &T, ll N) {
  int size = T.size();
  Matrix result(size, vector<ll>(size, 0));
  for (int i = 0; i < size; ++i) {
    result[i][i] = 1; // Identity matrix
  }
  while (N > 0) {
    if (N % 2 == 1) {
      result = multiply(result, T);
    }
    T = multiply(T, T);
    N /= 2;
  }
  return result;
}

int main() {
  ll A, B, C, D, N;
  cin >> A >> B >> C >> D >> N;

  Matrix T = {{A, B}, {C, D}};
  Matrix result = matrixExpo(T, N);

  int ukuleles = (result[0][0] + result[0][1]) % MOD;
  int vuvuzelas = (result[1][0] + result[1][1]) % MOD;

  cout << ukuleles << " " << vuvuzelas << endl;

  return 0;
}