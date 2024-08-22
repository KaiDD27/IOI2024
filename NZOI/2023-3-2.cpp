#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isSimple(const vector<int> &tiles) {
  for (int tile : tiles) {
    int num = tile % 10;
    if (num == 1 || num == 9)
      return false;
  }
  return true;
}

bool canFormGroups(vector<int> &tiles) {
  vector<int> counts(30, 0);
  for (int tile : tiles)
    counts[tile]++;
  for (int i = 1; i < 30; i++) {
    if (counts[i] >= 3)
      counts[i] -= 3;
    while (i <= 27 && counts[i] > 0 && counts[i + 1] > 0 && counts[i + 2] > 0) {
      counts[i]--;
      counts[i + 1]--;
      counts[i + 2]--;
    }
    if (counts[i] != 0)
      return false;
  }
  return true;
}

bool isComplete(vector<int> &tiles) {
  for (int i = 0; i < tiles.size() - 1; i++) {
    if (tiles[i] == tiles[i + 1]) {
      vector<int> remainingTiles = tiles;
      remainingTiles.erase(remainingTiles.begin() + i,
                           remainingTiles.begin() + i + 2);
      if (canFormGroups(remainingTiles))
        return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int pCnt, bCnt, cCnt;
  cin >> pCnt >> bCnt >> cCnt;

  vector<int> pbcCards;

  for (int i = 0; i < pCnt; i++) {
    int tile;
    cin >> tile;
    pbcCards.push_back(tile);
  }

  for (int i = 0; i < bCnt; i++) {
    int tile;
    cin >> tile;
    pbcCards.push_back(tile + 10);
  }

  for (int i = 0; i < cCnt; i++) {
    int tile;
    cin >> tile;
    pbcCards.push_back(tile + 20);
  }

  if (pbcCards.size() != 14) {
    cout << "SAD" << endl;
    return 0;
  }

  bool simple = isSimple(pbcCards);
  bool complete = isComplete(pbcCards);

  if (simple && complete)
    cout << "WIN" << endl;
  else if (complete)
    cout << "COMPLETE" << endl;
  else if (simple)
    cout << "SIMPLE" << endl;
  else
    cout << "SAD" << endl;

  return 0;
}