#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

enum BreedState { NONE, HG, GH };

int main() {
  int N = 0;
  string strBreed = "";

  cin >> N;
  cin >> strBreed;

  int ans = 0;
  BreedState breedState = NONE;

  for (int i = 0; i < N; i += 2) {
    if (strBreed[i] == 'H' && strBreed[i + 1] == 'G') {
      if (breedState == GH) {
        reverse(strBreed.begin(), strBreed.begin() + i);
        ans++;
      }
      breedState = HG;
    } else if (strBreed[i] == 'G' && strBreed[i + 1] == 'H') {
      if (breedState == HG) {
        reverse(strBreed.begin(), strBreed.begin() + i);
        ans++;
      }
      breedState = GH;
    }
  }
  if (breedState == GH) {
    ans++;
  }

  cout << ans << endl;

  return 0;
}
