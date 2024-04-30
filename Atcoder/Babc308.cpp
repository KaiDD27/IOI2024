#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> eatColor;
vector<string> color;
vector<int> price;
map<string, int> colorToPrice;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  eatColor.resize(n);
  color.resize(m + 1);
  price.resize(m + 1);
  for (auto &ei : eatColor)
    cin >> ei;
  for (int i = 1; i <= m; i++)
    cin >> color[i];
  for (auto &pi : price)
    cin >> pi;
  for (int i = 1; i <= m; i++) {
    colorToPrice[color[i]] = price[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (colorToPrice.count(eatColor[i])) {
      sum += colorToPrice[eatColor[i]];
    } else {
      sum += price[0];
    }
  }
  cout << sum << endl;
  return 0;
}