#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int l;
  cin >> l;
  array<int, 4> ducks{};
  int quackers_left = 0;

  for (int i = 0; i < 4; ++i) {
    cin >> ducks[i];
    if (i != 3) {
      quackers_left += ducks[i];
    }
  }

  cin.ignore(); // Ignore the newline character after the last integer input
  string wants;
  getline(cin, wants);

  int days = 0;
  for (char type : wants) {
    if (type != 'G' && quackers_left <= 0)
      break;

    if (type == 'R') {
      if (ducks[0] < 1)
        break;
      --ducks[0];
      --quackers_left;
    } else if (type == 'P') {
      if (ducks[1] < 1)
        break;
      --ducks[1];
      --quackers_left;
    } else if (type == 'D') {
      if (ducks[2] < 1)
        break;
      --ducks[2];
      --quackers_left;
    } else if (type == 'G') {
      // goose is not a duck
      if (ducks[3] < 1)
        break;
      --ducks[3];
    } else {
      // wildcard
      if (quackers_left < 1)
        break;
      --quackers_left;
    }
    ++days;
  }

  // Return number of days and number of ducks left (including geese)
  cout << days << '\n' << quackers_left + ducks[3] << '\n';

  return 0;
}
