#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long c;
  cin >> N >> c;
  vector<long long> hs(N + 1); // + 1 so we don't overrun k + 1
  for (int j = 0; j < N; j++)
    cin >> hs[j];

  sort(hs.begin(), hs.end(), std::greater<long long>());

  long long n_deployed = 0;
  for (int k = 0; k < N; k++) {
    int i = k + 1; // calculate first non-profitable height or the next
                   // tree height if all heights in between are profitable
    long long h = std::max(c / (i * 5), hs[k + 1]);

    // add profitable heights between current height and h
    if (h < hs[k])
      n_deployed += hs[k] - h;
  }

  cout << n_deployed << endl;
}
