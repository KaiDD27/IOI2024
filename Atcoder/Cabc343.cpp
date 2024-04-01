#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> dp;
void init() {
  for (ll num = 1; num <= 1e6; num++) {
    ll cubicPower = num * num * num;
    string str = to_string(cubicPower);
    bool isValid = true;
    for (int i = 0, j = str.length() - 1; i <= j; i++, j--) {
      if (str[i] != str[j]) {
        isValid = false;
        break;
      }
    }
    if (isValid == true)
      dp.push_back(cubicPower);
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll N;
  cin >> N;
  init();
  auto it = upper_bound(dp.begin(), dp.end(), N);
  cout << *(--it) << endl;
  return 0;
}