#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int total = 0;
  for (int i = 0; i < N; i++) {
    total += v[i];
  }

  int accuracy = min(100, total / 2);
  int attack = total - accuracy;

  cout << accuracy * attack << endl;

  return 0;
}