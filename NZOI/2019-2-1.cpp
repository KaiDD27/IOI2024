#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> tea = {"Ginger",     "Chamomile", "Earl Gray",
                      "Peppermint", "Lemon",     "Strawberry"};
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  for (int i = 0; i < 6; i++) {
    int cnt;
    cin >> cnt;
    cout << tea[i] << " " << 240 * cnt << endl;
  }
  return 0;
}