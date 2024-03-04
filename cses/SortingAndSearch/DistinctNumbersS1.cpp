#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> x;
int main(void) {
  int n;
  cin >> n;
  x.resize(n);
  for (auto &a : x)
    cin >> a;
  sort(x.begin(), x.end());
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (x[i] != x[i - 1])
      count++;
  }
  cout << count << endl;
  return 0;
}