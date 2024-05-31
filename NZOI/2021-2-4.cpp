#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
string strW;
ll ans;
ll l;
map<string, ll> mpAns;
bool vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  return false;
}
ll decode() {
  if (l >= 5 && strW.substr(l - 4) == "uack") {
    if (vowel(strW[0])) {
      for (int i = l - 5; i > 0; i--) {
        if (!vowel(strW[i]))
          mpAns["uack"]++;
        else
          break;
      }
    } else {
      mpAns["uack"] = 1;
      for (int i = 0; i <= l - 5; i++) {
        if (vowel(strW[i])) {
          mpAns["uack"] = 0;
          break;
        }
      }
    }
  }
  if (l >= 3 && strW.substr(l - 2) == "ck") {
    if (!vowel(strW[0])) {
      for (int i = l - 3; i > 0; i--) {
        if (vowel(strW[i]))
          mpAns["ck"]++;
        else
          break;
      }
    } else {
      mpAns["ck"] = 1;
      for (int i = 0; i <= l - 3; i++) {
        if (!vowel(strW[i])) {
          mpAns["ck"] = 0;
          break;
        }
      }
    }
  }
  if (l >= 4 && strW.find("lf") != string::npos) {
    mpAns["lf"] = 1;
    bool flagVowel = false;
    for (int i = 0; i < l;) {
      if (vowel(strW[i])) {
        flagVowel = true;
        if (i <= l - 4 && strW[i + 1] == 'l' && strW[i + 2] == 'f' &&
            strW[i + 3] == strW[i]) {
          i += 4;
        } else {
          mpAns["lf"] = 0;
          break;
        }
      } else {
        i++;
      }
    }
    if (flagVowel == false)
      mpAns["lf"] = 0;
  }
  if (l >= 4 && strW.substr(l - 3) == "onk") {
    mpAns["onk"] = 1;
    for (int i = 0; i <= l - 4; i++) {
      if (vowel(strW[i])) {
        mpAns["onk"] = 0;
        break;
      }
    }
  }
  ll res = 0;
  for (auto mi : mpAns)
    res += mi.second;
  return res;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> l;
  cin >> strW;
  cout << decode() << endl;
  return 0;
}