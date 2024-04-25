#include <iostream>

using namespace std;

const string t = "wbwbwwbwbwbw";

int main() {
  int w, b;
  cin >> w >> b;
  for (int i = 0; i < (int)t.size(); i++) {
    int nw = 0, nb = 0;
    for (int j = 0; j < w + b; j++) {
      if (t[(i + j) % t.size()] == 'w')
        ++nw;
      else
        ++nb;
    }
    if (w == nw and b == nb) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
