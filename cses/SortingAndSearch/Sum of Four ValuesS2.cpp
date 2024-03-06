#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unordered_map<int, vector<pair<int, int>>> pairs;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int current_sum = a[i] + a[j];
      if (pairs.count(x - current_sum)) {
        for (auto &p : pairs[x - current_sum]) {
          if (p.first != i && p.first != j && p.second != i && p.second != j) {
            cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " "
                 << j + 1 << "\n";
            return 0;
          }
        }
      }
      pairs[current_sum].push_back({i, j});
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}