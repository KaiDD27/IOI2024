#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strShoes;
  cin >> strShoes;
  ll redCnt = 0;
  for (auto si : strShoes) {
    if (si == 'R')
      redCnt++;
  }
  if (redCnt == 2)
    cout << "Dorothy is in the classroom." << endl;
  if (redCnt == 0)
    cout << "Maybe Dorothy is in Kansas." << endl;
  if (redCnt == 1)
    cout << "Hop along Dorothy and find that other shoe." << endl;
  return 0;
}