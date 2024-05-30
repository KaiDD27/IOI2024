#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  vector<ll> n3(3);
  ll maxN = 0;
  for (auto &ni : n3) {
    cin >> ni;
    maxN = max(maxN, ni);
  }
  vector<char> vc = {'S', 'M', 'L'};
  for (int i = 2; i >= 0; i--) {
    for (ll j = 0; j < maxN; j++) {
      if (j >= (maxN - n3[i]) / 2 && j < (maxN - n3[i]) / 2 + n3[i])
        cout << vc[i];
      else
        cout << '_';
    }
    cout << endl;
  }

  return 0;
}