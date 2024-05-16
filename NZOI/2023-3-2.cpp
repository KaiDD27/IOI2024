#include <array>
#include <cstdio>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> pbcCards;

void deleteSets(vector<int> &cards, int cnt) {
  for (int g = 0; g < cnt; g++) {
    for (int i = 1; i < 13; i++) {
      if (cards[i] != 0 && cards[i] == cards[i - 1] &&
          cards[i] == cards[i + 1]) {
        cards[i] = 0;
        cards[i - 1] = 0;
        cards[i + 1] = 0;
        break;
      }
    }
  }
  return;
}
void deleteStraights(vector<int> &cards, int cnt) {
  for (int g = 0; g < cnt; g++) {
    int index = 0;
    int pre = 0;
    for (int i = 0; i < 14; i++) {
      if (cards[i] != 0) {
        if (index == 0) {
          index++;
          pre = cards[i];
          cards[i] = 0;
        } else {
          if (cards[i] == pre + 1) {
            index++;
            pre = cards[i];
            cards[i] = 0;
          }
        }
      }
      if (index == 3)
        break;
    }
  }
  return;
}
bool isCardsEmpty(vector<int> cards) {
  for (int i = 0; i < 14; i++) {
    if (cards[i] != 0)
      return false;
  }
  return true;
}

bool containFourGroups(vector<int> cards) {

  vector<int> tmpCards = cards;
  deleteSets(tmpCards, 4);
  if (isCardsEmpty(tmpCards))
    return true;

  tmpCards = cards;
  deleteSets(tmpCards, 3);
  deleteStraights(tmpCards, 1);
  if (isCardsEmpty(tmpCards))
    return true;

  tmpCards = cards;
  deleteSets(tmpCards, 2);
  deleteStraights(tmpCards, 2);
  if (isCardsEmpty(tmpCards))
    return true;

  tmpCards = cards;
  deleteSets(tmpCards, 1);
  deleteStraights(tmpCards, 3);
  if (isCardsEmpty(tmpCards))
    return true;

  tmpCards = cards;
  deleteStraights(tmpCards, 4);
  if (isCardsEmpty(tmpCards))
    return true;

  return false;
}

bool isComplete(vector<int> cards) {
  for (int i = 1; i < 14; i++) {
    if (cards[i] == cards[i - 1]) {
      vector<int> tmpCards = cards;
      tmpCards[i] = 0;
      tmpCards[i - 1] = 0;
      if (containFourGroups(tmpCards))
        return true;
    }
  }
  return false;
}

bool isSimple(const vector<int> &cards) {
  for (int i = 0; i < 14; i++) {
    if (cards[i] % 10 == 1 || cards[i] % 10 == 9)
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int pCnt, bCnt, cCnt;
  cin >> pCnt >> bCnt >> cCnt;
  if (pCnt + bCnt + cCnt != 14) {
    cout << "SAD" << endl;
    return 0;
  }
  while (pCnt != 0) {
    int pi;
    cin >> pi;
    pbcCards.push_back(pi);
    pCnt--;
  }
  while (bCnt != 0) {
    int bi;
    cin >> bi;
    pbcCards.push_back(bi + 10);
    bCnt--;
  }
  while (cCnt != 0) {
    int ci;
    cin >> ci;
    pbcCards.push_back(ci + 20);
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