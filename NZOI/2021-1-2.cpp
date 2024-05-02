#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> strNums = {"2", "3",  "4", "5", "6", "7", "8",
                          "9", "10", "J", "Q", "K", "A"};
vector<string> strSuits = {"spades", "clubs", "diamonds", "hearts"};
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  string strNum;
  string strSuit;
  cin >> strNum >> strSuit;
  int ans = strNums.size() * strSuits.size();
  for (int i = 0; i < strSuit.size(); i++) {
    if (strSuit == strSuits[i]) {
      ans = ans - i * strNums.size();
    }
  }
  for (int i = 0; i < strNums.size(); i++) {
    if (strNum == strNums[i]) {
      ans = ans - (i + 1);
    }
  }
  cout << ans << endl;
  return 0;
}