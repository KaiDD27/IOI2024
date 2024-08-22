#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long; // Using ll as an alias for long long
#define endl "\n"

ll N, T;
vector<ll> boxes;
vector<ll> counts(100001, 0);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> T;

  boxes.resize(N);

  for (ll i = 0; i < N; i++) {
    cin >> boxes[i];
  }

  for (ll x : boxes) {
    counts[x]++;
  }

  ll time = T;
  for (ll idx = 1; idx < 100000; idx++) {
    ll delta = min(counts[idx], time);
    counts[idx + 1] += delta;
    counts[idx] -= delta;
    time -= delta;
  }

  time = T - time; // we might not have used all of our time
  for (ll idx = 100000; idx > 1; idx--) {
    ll delta = min(counts[idx], time);
    counts[idx - 1] += delta;
    counts[idx] -= delta;
    time -= delta;
  }

  // find the largest and smallest box sizes where count > 0
  ll largest = 0, smallest = 100000;
  for (ll idx = 1; idx <= 100000; idx++) {
    if (counts[idx] > 0) {
      largest = max(largest, idx);
      smallest = min(smallest, idx);
    }
  }

  cout << largest - smallest << endl;

  return 0;
}