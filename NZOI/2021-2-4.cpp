#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll l, ans;
string strW;
map<string, ll> mpAns;
bool vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void validDecodeMany(string endStr, bool flagVowel) {
  ll len = endStr.length();
  if (l >= len + 1 && strW.substr(l - len) == endStr) {
    for (int i = l - len - 1; i > 0; i--) {
      if (vowel(strW[i]) != flagVowel)
        mpAns[endStr]++;
      else
        break;
    }
  }
}
void validDecodeSingle(string endStr, bool flagVowel) {
  ll len = endStr.length();
  if (l >= len + 1 && strW.substr(l - len) == endStr) {
    mpAns[endStr] = 1;
    for (int i = 0; i < l - len; i++) {
      if (vowel(strW[i]) != flagVowel) {
        mpAns[endStr] = 0;
        break;
      }
    }
  }
}

void decode() {
  if (vowel(strW[0])) {
    validDecodeMany("uack", true);
    validDecodeSingle("ck", true);
  } else {
    validDecodeMany("ck", false);
    validDecodeSingle("uack", false);
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
    if (!flagVowel)
      mpAns["lf"] = 0;
  }
  validDecodeSingle("onk", false);
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> l;
  cin >> strW;
  decode();
  for (auto mi : mpAns)
    ans += mi.second;
  cout << ans << endl;
  return 0;
}