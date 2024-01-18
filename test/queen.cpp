#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int DIM = 8;

int main() {
  vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
  for (int r = 0; r < DIM; r++) {
    string str;
    cin >> str;

    for (int c = 0; c < DIM; c++) {
      blocked[r][c] = (str[c] == '*');
    }
  }

  vector<int> queen(DIM);
  for (int i = 0; i < DIM; i++) {
    queen[i] = i;
  }
  int valid_num = 0;
  do {
    bool works = true;
    vector<bool> diagnalsOne(DIM * 2 - 1, false);
    vector<bool> diagnalsTwo(DIM * 2 - 1, false);
    for (int c = 0; c < DIM; c++) {
      if (blocked[queen[c]][c] == true) {
        works = false;
        break;
      }

      if (diagnalsOne[c + queen[c]] == false) {
        diagnalsOne[c + queen[c]] = true;
      } else {
        works = false;
        break;
      }

      if (diagnalsTwo[c - queen[c] + DIM - 1] == false) {
        diagnalsTwo[c - queen[c] + DIM - 1] = true;
      } else {
        works = false;
        break;
      }
    }
    if (works == true) valid_num++;
  } while (next_permutation(queen.begin(), queen.end()));

  cout << valid_num << endl;
  return 0;
}