#include <algorithm>


using namespace std;
int playerId[200100], tmp[200100];
int playerS[200100], playerW[2000100];
int main() {
  int N;
  auto compare = [](int j, int k) {
    return playerS[j] != playerS[k] ? playerS[j] > playerS[k] : j < k;
  };

  sort(playerId, playerId + 2 * N, compare); // sort性能不足
}