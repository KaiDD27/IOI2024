#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<string, ll> mpShoeCnt;
map<string, string> mpShortLong;
string strShoes;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> strShoes;
  strShoes += "E";
  mpShoeCnt = {{"G", 0}, {"B", 0}, {"R", 0}, {"Bl", 0}, {"Br", 0}, {"M", 0}};
  mpShortLong = {{"G", "Green"}, {"B", "Black"},  {"R", "Red"},
                 {"Bl", "Blue"}, {"Br", "Brown"}, {"M", "Mustard"}};
  for (int i = 0; i < strShoes.length() - 1; i++) {
    if (strShoes[i + 1] == 'l' || strShoes[i + 1] == 'r')
      mpShoeCnt[strShoes.substr(i, 2)]++;
    else if (mpShoeCnt.count(strShoes.substr(i, 1))) {
      mpShoeCnt[strShoes.substr(i, 1)]++;
    }
  }
  bool flagAllPaired = true;
  vector<string> output = {"G", "B", "R", "Bl", "Br", "M"};
  for (auto oi : output) {
    if (mpShoeCnt[oi] % 2 != 0) {
      cout << "A " << mpShortLong[oi] << " shoe has no partner." << endl;
      flagAllPaired = false;
    }
  }
  if (flagAllPaired == true)
    cout << "All paired up!" << endl;
  return 0;
}