#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n, k;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> k;
  vector<int> threefaulty;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    if (q < k) {
      threefaulty.push_back(q);
      if (threefaulty.size() == 3) {
        cout << "Fault Detected" << endl;
        for (auto ti : threefaulty)
          cout << ti << " ";
        return 0;
      }
    } else {
      threefaulty.clear();
    }
  }
  cout << "No Fault" << endl;
  return 0;
}