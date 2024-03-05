#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
#define endl '\n'
map<int, int> a;

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    if (a.count(x - num)) {
      cout << a[x - num] << " " << i << endl;
      return 0;
    }
    a[num] = i;
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}