#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> digitals;
ll pow10(int x) {
  ll powX = 1;
  for (int i = 0; i < x; i++) {
    powX = powX * 10;
  }
  return powX;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  ll tmp = n;
  while (tmp > 0) {
    digitals.push_back(tmp % 10);
    tmp = tmp / 10;
  }
  ll cnt = 0;
  for (int i = digitals.size() - 1; i >= 0; i--) {
    cnt += (digitals[i] * pow10(i - 1) * i);
    if (digitals[i] > 3)
      cnt += (pow10(i));
    else if (digitals[i] == 3) {
      cnt += (n % (pow10(i)) + 1);
    }
  }
  cout << cnt << endl;
  return 0;
}