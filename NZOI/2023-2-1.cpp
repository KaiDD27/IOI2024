#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
vector<ll> expense;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  expense.resize(n);
  ll sumE = 0;
  for (auto &ei : expense) {
    cin >> ei;
    sumE += ei;
  }
  if (sumE % n == 0)
    cout << 0 << endl;
  else {
    cout << sumE / n + 1 - sumE % (sumE / n + 1) << endl;
  }
  return 0;
}