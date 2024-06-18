#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<bool> hayAllCowLike;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    hayAllCowLike.clear();
    hayAllCowLike.resize(N + 1);
    for (int i = 0, preNum = 0, prePreNum = 0; i < N; i++) {
      int currNum;
      cin >> currNum;
      if (currNum == preNum || currNum == prePreNum)
        hayAllCowLike[currNum] = true;
      prePreNum = preNum;
      preNum = currNum;
    }
    bool needBlankBefore = false;
    for (int i = 1; i <= N; i++) {
      if (hayAllCowLike[i] == true) {
        if (needBlankBefore == true)
          cout << " " << i;
        else {
          needBlankBefore = true;
          cout << i;
        }
      }
    }
    if (needBlankBefore == false)
      cout << "-1";
    cout << endl;
  }
  return 0;
}