#include <iostream>
using namespace std;
struct carpet {
  int a = 0, b = 0, g = 0, k = 0;
};
carpet carpets[10000 + 5];
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
  }
  cin >> x >> y;
  for (int i = n; i >= 1; i--) {
    if (x <= carpets[i].a + carpets[i].g && x >= carpets[i].a &&
        y <= carpets[i].b + carpets[i].k && y >= carpets[i].b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}