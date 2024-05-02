#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a(9);
vector<int> b(9);
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll sumA = 0, sumB = 0;
  for (auto &ai : a) {
    cin >> ai;
    sumA += ai;
  }
  for (int i = 0; i < 8; i++) {
    cin >> b[i];
    sumB += b[i];
  }
  cout << sumA - sumB + 1 << endl;

  return 0;
}