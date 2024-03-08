#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> subwayLength;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int N;
  cin >> N;
  int headLength = 0, tailLength = 0;
  string strCows;
  cin >> strCows;

  if (*strCows.begin() == '1') {
    for (int i = 0; i < strCows.length(); i++) {
      if (strCows[i] == '0') {
        headLength = i;
        break;
      }
    }
  }
  int tmpLength = 0;
  for (int i = headLength; i < strCows.length(); i++) {
    if (strCows[i] == '1')
      tmpLength++;
    else {
      if (tmpLength != 0) {
        subwayLength.push_back(tmpLength);
        tmpLength = 0;
      }
    }
  }
  tailLength = tmpLength;

  return 0;
}