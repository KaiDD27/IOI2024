#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> x, y;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  ll sumX = 0, sumY = 0;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    sumX += x;
    sumY += y;
  }
  if (sumX > sumY)
    cout << "Takahashi" << endl;
  else if (sumX < sumY)
    cout << "Aoki" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}