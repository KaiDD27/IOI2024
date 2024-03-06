#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;
#define endl '\n'
vector<ll> t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  t.resize(n);
  ll sum = 0;
  ll maxA = 0;
  for (auto &i : t) {
    cin >> i;
    maxA = max(maxA, i);
    sum += i;
  }
  cout << max(maxA * 2, sum) << endl;
  return 0;
}