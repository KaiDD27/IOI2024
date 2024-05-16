#include <array>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> pbcCards(31);
bool containFourGroups(vector<int> &cards) {
  vector<array<int, 2>> suit(4, {0, 0});
  for (int i = 1; i < cards.size();) {
    if (cards[i] == 0) {
      i++;
      continue;
    }
    bool isAdd = false;
    for (int s = 0; s < 4; s++) {
      if (suit[s][1] == 3)
        continue;
      if (suit[s][1] == 0) {
        suit[s][0] = i;
        suit[s][1]++;
        cards[i]--;
        isAdd = true;
        if (cards[i] == 0) {
          i++;
          break;
        }
      } else if (suit[s][1] != 0) {
        if (i != suit[s][0] + suit[s][1]) {
          continue;
        } else {
          suit[s][1]++;
          cards[i]--;
          isAdd = true;
          if (cards[i] == 0) {
            i++;
            break;
          }
        }
      }
    }
    if (isAdd == false)
      return false;
  }
  return true;
}

bool isComplete(const vector<int> &cards) {
  vector<int> tmpCards;
  for (int i = 1; i < cards.size(); i++) {
    if (cards[i] >= 2) {
      tmpCards = cards;
      tmpCards[i] -= 2;
      if (containFourGroups(tmpCards))
        return true;
    }
  }
  return false;
}

bool isSimple(const vector<int> &cards) {
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i] > 0 && (i % 10 == 1 || i % 10 == 9))
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int pCnt, bCnt, cCnt;
  cin >> pCnt >> bCnt >> cCnt;

  while (pCnt != 0) {
    int pi;
    cin >> pi;
    pbcCards[pi]++;
    pCnt--;
  }
  while (bCnt != 0) {
    int bi;
    cin >> bi;
    pbcCards[bi + 10]++;
    bCnt--;
  }
  while (cCnt != 0) {
    int ci;
    cin >> ci;
    pbcCards[ci + 20]++;
    cCnt--;
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