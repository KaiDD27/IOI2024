#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K, U;
  cin >> N >> M >> K >> U;

  vector<long long> distance(N, 0);
  for (int i = 1; i < N; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    distance[i] = distance[i - 1] + w;
  }

  vector<int> trout_count(N + 1, 0);
  for (int i = 0; i < M; ++i) {
    int L, D;
    cin >> L >> D;
    int left = lower_bound(distance.begin(), distance.end(), distance[L] - D) -
               distance.begin();
    trout_count[left]++;
    trout_count[L + 1]--;
  }

  for (int i = 1; i <= N; ++i) {
    trout_count[i] += trout_count[i - 1];
  }

  for (int i = 0; i < K; ++i) {
    char type;
    int q;
    cin >> type >> q;
    if (type == 'Q') {
      cout << trout_count[q] << '\n';
    }
  }

  return 0;
}
