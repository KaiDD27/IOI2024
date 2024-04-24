#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<array<int, 3>> Point;
vector<int> ans;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  Point.resize(n + 1);
  ans.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> Point[i][1] >> Point[i][2];
    Point[i][0] = i;
  }
  for (int i = 1; i <= n; i++) {
    ll largesetDist = 0;
    int xi = Point[i][1], yi = Point[i][2];
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      int xj = Point[j][1], yj = Point[j][2];
      ll dist = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
      if (dist > largesetDist) {
        largesetDist = dist;
        ans[i] = j;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << endl;
  return 0;
}