#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
    if (s.find(a[i] - 1) == s.end()) {
      s.erase(a[i]);
    }
  }

  cout << s.size() << "\n";
  while (m--) {
    int i, j;
    cin >> i >> j;
    swap(a[i], a[j]);

    // Update set for a[i]
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      s.insert(a[i]);
    } else if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      s.erase(a[i]);
    }

    // Update set for a[j]
    if (a[j] < a[j - 1] && a[j] < a[j + 1]) {
      s.insert(a[j]);
    } else if (a[j] > a[j - 1] && a[j] > a[j + 1]) {
      s.erase(a[j]);
    }

    cout << s.size() << "\n";
  }

  return 0;
}