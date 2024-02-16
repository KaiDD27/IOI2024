#include <cstdlib>
#include <iostream>
using namespace std;
int playersCard[11], botCard[11];
int main() {
  while (true) {
    srand(time(0));
    cout << "1to10cards card number more bigger the more bigger the card is"
         << endl;
    for (int i = 1; i <= 10; i++) {
      playersCard[i] = rand() % 4;
      cout << playersCard[i] << "times card" << i << "is yours" << endl;
    }
    for (int i = 1; i <= 10; i++) {
      botCard[i] = rand() % 4;
    }
    int cardTotal = 1, i = 0, botAns = 0;
    while (++i) {
      int pastCardNum;
      cout << "A pair or one card" << endl
           << "If a pair type 2,if a card type 1" << endl
           << "then type the card you want to use. if you dont want to use a "
              "bigger card type 0.";
      int cardNum;
      cin >> cardNum;
      if (cardNum == 0) {
        int botPair = 0;
        for (int j = 1; j <= 10; j++) {
          if (botCard[j] >= 2) {
            botPair++;
          }
        }
        int botOnlyCard = 0;
        for (int j = 1; j <= 10; j++) {
          if (botCard[j] == 1) {
            botOnlyCard++;
          }
        }
        if (botOnlyCard > botPair) {
          for (int j = 1; j <= 10; j++) {
            if (botCard[j] == 1) {
              pastCardNum = 1;
              cout << j << endl;
              botAns = j;
              i = 0;
              botCard[j]--;
              break;
            }
          }
        } else if (botPair >= botOnlyCard) {
          for (int j = 1; j <= 10; j++) {
            if (botCard[j] >= 2) {
              pastCardNum = 2;
              cout << j << " " << j << endl;
              botCard[j] -= 2;
              botAns = j;
              i = 0;
              break;
            }
          }
        }
      } else if (cardNum == 1) {
        int card;
        cin >> card;
        if (playersCard[card] < 1 || (i != 1 && card <= botAns) ||
            (i != 1 && pastCardNum != 1)) {
          cout << "you cheat" << endl;
        } else {
          pastCardNum = 1;
          if (card == 10) {
            cout << "yours turn" << endl;
            i = 0;
            botAns = 0;
          }
          playersCard[card]--;
          for (int j = card + 1; j <= 10; j++) {
            if (botCard[j] == 1 || (j >= 8)) {
              cout << j << endl;
              botAns = j;
              botCard[j]--;
              break;
            }
            if (j == 10) {
              cout << "yours turn" << endl;
              botAns = 0;
              i = 0;
            }
          }
        }
      } else if (cardNum == 2) {
        int card;
        cin >> card;
        if (playersCard[card] < 2 || (i != 1 && card <= botAns) ||
            (i != 1 && pastCardNum != 2)) {
          cout << "you cheat" << endl;
        } else {
          pastCardNum = 2;
          if (card == 10) {
            cout << "yours turn" << endl;
            botAns = 0;
            i = 0;
          }
          playersCard[card] -= 2;
          for (int j = card + 1; j <= 10; j++) {
            if (botCard[j] >= 2) {
              cout << j << " " << j << endl;
              botCard[j] -= 2;
              botAns = j;
              break;
            }
            if (j == 10) {
              cout << "yours turn" << endl;
              botAns = 0;
              i = 0;
            }
          }
        }
      }
      for (int i = 1; i <= 10; i++) {
        cout << " " << playersCard[i] << " " << i << " " << endl;
      }
      bool doneGame = false;
      for (int j = 1; j <= 10; j++) {
        if (botCard[j] != 0) {
          break;
        }
        if (j == 10) {
          doneGame = true;
          cout << " I wins HAHAHAHAHA" << endl;
        }
      }
      for (int j = 1; j <= 10; j++) {
        if (playersCard[j] != 0) {
          break;
        }
        if (j == 10) {
          doneGame = true;
          cout << " you wins" << endl << endl;
        }
      }
      if (doneGame) {
        break;
      }
    }

    cout << "bye bye happy new year!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
         << endl;
  }
}