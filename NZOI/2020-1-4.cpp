#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll sumRate;
ll n;
ll getMinSum(vector<ll> &difficulty) {
  ll startSum = 0;
  for (int i = 0; i < n; i++) {
    startSum += difficulty[i] * (n - i);
  }
  ll sum = startSum;
  ll minSum = startSum;
  // 左开右闭,所以 i 最大到n-2即可，不然就越界了，共计算了 n-1 种可能，加上
  // startSum 总共就是 n 种了,
  for (int i = 0; i < n - 1; i++) {
    // 减去左边的一天
    sum -= difficulty[i] * n;
    // 剩下的部分，每天都要加 1，再加上右边新增的一天，正好就是加一个 sumRate
    sum += sumRate;
    minSum = min(minSum, sum);
  }
  return minSum;
}
vector<ll> difficulty;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  difficulty.resize(n);
  for (auto &di : difficulty) {
    cin >> di;
    sumRate += di;
  }
  // 拆环为线difficulty.end()，可以进行--操作，也可以prev（）来操作
  difficulty.insert(difficulty.end(), difficulty.begin(),
                    prev(difficulty.end()));
  ll minSum = getMinSum(difficulty);
  reverse(difficulty.begin(), difficulty.end());
  minSum = min(minSum, getMinSum(difficulty));
  cout << minSum << endl;
  return 0;
}