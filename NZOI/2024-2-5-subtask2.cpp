#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1005; // Assuming N <= 1000 for Subtask 2

int N, M, K, U;
vector<pair<int, int>> parent(MAXN, {-1, 0});
vector<int> trout_count(MAXN, 0);

void add_trout(int position, int distance) {
  while (distance >= 0) {
    trout_count[position]++;
    if (position == 0)
      break;
    distance -= parent[position].second;
    position = parent[position].first;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K >> U;

  for (int i = 0; i < N - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    parent[b] = {a, w};
  }

  for (int i = 0; i < M; i++) {
    int L, D;
    cin >> L >> D;
    add_trout(L, D);
  }

  for (int i = 0; i < K; i++) {
    char query_type;
    cin >> query_type;
    if (query_type == 'Q') {
      int q;
      cin >> q;
      cout << trout_count[q] << '\n';
    } else {
      int L, D;
      cin >> L >> D;
      add_trout(L, D);
    }
  }

  return 0;
}
