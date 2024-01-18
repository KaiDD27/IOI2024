#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main(void) {
  ifstream fin("herding.in");
  ofstream fout("herding.out");

  vector<int> cows(3);
  fin >> cows[0] >> cows[1] >> cows[2];
  int min_val = min(cows[0], min(cows[1], cows[2]));
  int max_val = max(cows[0], max(cows[1], cows[2]));
  int mid_val = cows[0] + cows[1] + cows[2] - min_val - max_val;

  if ((max_val - mid_val == 1) && (mid_val - min_val == 1)) {
    fout << 0 << endl;
    fout << 0 << endl;
    return 0;
  }

  if ((max_val - mid_val == 2) || (mid_val - min_val == 2)) {
    fout << 1 << endl;
  } else {
    fout << 2 << endl;
  }
  fout << max((max_val - mid_val), (mid_val - min_val)) - 1 << endl;
  return 0;
}