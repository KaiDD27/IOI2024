#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, k;
vector<ll> x;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  // n<=65536,k<=16
  cin >> n >> k;
  x.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> x[i];

  return 0;
}