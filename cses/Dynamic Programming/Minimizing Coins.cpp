#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> c;
vector<int> minNumOfCoin;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, x;
  cin >> n >> x;
  c.resize(n);
  for (auto &ci : c)
    cin >> ci;
  minNumOfCoin.resize(x + 1);
  minNumOfCoin[0] = 0;
  for (int i = 1; i <= x; i++) {
    minNumOfCoin[i] = x + 1; // x 个面值为1 的硬币是上限。
    for (auto ci : c) {
      if (i - ci >= 0)
        minNumOfCoin[i] = min(minNumOfCoin[i], minNumOfCoin[i - ci] + 1);
    }
  }
  if (minNumOfCoin[x] != x + 1)
    cout << minNumOfCoin[x] << endl;
  else
    cout << "-1" << endl;
  return 0;
}