#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {
  ifstream cin("primenumber.in");
  ofstream cout("primenumber.out");
  int N;
  cin >> N;
  vector<int> Number(N);
  for (int n = 0; n < N; n++) {
    cin >> Number[n];
  }

  for (int n = 0; n < N; n++) {
    bool boolPrime = true;
    for (int i = 2; i < Number[n]; i++) {
      if (Number[n] % i == 0) {
        boolPrime = false;
        break;
      }
    }
    if (boolPrime == true) {
      cout << Number[n];
      cout << " ";
    }
  }
}