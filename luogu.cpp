#include <iostream>
#include <string>
using namespace std;
string ans[15];
string variableName[105];
int variableO[105];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int L;
    string strO;
    cin >> L >> strO;
    int w = 0;
    if (strO == "O(1)")
      w = 0;
    else {
      int j = 0;
      while (strO[j] != ')') {
        if (strO[j] >= '0' && strO[j] <= '9') {
          w *= 10;
          w += (strO[j] - '0');
        }
        j++;
      }
    }

    if (L % 2 != 0) {
      ans[i] = "ERR";
    }

    int variableNameCount = 0;
    int maxO = 0;
    int currO = 0;
    for (int j = 1; j <= L; j++) {
      string strTmp;

      string strPrev, strCurr;
      cin >> strCurr;
      if (strCurr == "E" && variableNameCount == 0) {
        ans[i] = "ERR";
        continue;
      } else if (strCurr == "E") {
        currO -= variableO[variableNameCount--];
      }

      if (strCurr == "F") {
        string strVar;
        cin >> strVar;
        cin >> strPrev >> strCurr;
        bool duplicateName = false;
        for (int l = 1; l <= variableNameCount; l++) {
          if (strVar == variableName[l]) {
            duplicateName = true;
            break;
          }
        }
        if (duplicateName == true) {
          ans[i] = "ERR";
        }

        variableName[++variableNameCount] = strVar;
        if (strPrev != "n" && strCurr == "n") {
          variableO[variableNameCount] = 1;
          currO += variableO[variableNameCount];
          maxO = max(maxO, currO);
        } else if (strPrev == "n" && strCurr != "n") {
          variableO[variableNameCount] = -105;
          currO += variableO[variableNameCount];
        } else if (strPrev == "n" && strCurr == "n") {
          variableO[variableNameCount] = 0;
        } else if (stoi(strPrev) > stoi(strCurr)) {
          variableO[variableNameCount] = -105;
          currO += variableO[variableNameCount];
        } else {
          variableO[variableNameCount] = 0;
        }
      }
    }
    if (ans[i] != "ERR") {
      if (maxO == w)
        ans[i] = "Yes";
      else
        ans[i] = "No";
      if (variableNameCount != 0)
        ans[i] = "ERR";
    }
  }

  for (int i = 1; i <= t; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
