#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, q;
vector<string> nString;
vector<bool> ascRes, descRes;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> q;
  nString.resize(n + 1);
  ascRes.resize(n + 1);
  descRes.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> nString[i];
  }
  ll alwayTrueLeftIdx = 1e6 + 10, alwayTrueRightIdx = -1;
  for (int i = 1; i <= n; i++) {
    ascRes[i] = nString[i] == "true" ? true : false;
    if (i != 1 && i % 2 == 1) {
      if (nString[i - 1] == "and")
        ascRes[i] = ascRes[i - 2] && ascRes[i];
      else {
        if (ascRes[i - 2] == true) {
          alwayTrueLeftIdx = i;
          break;
        }
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    descRes[i] = nString[i] == "true" ? true : false;
    if (i != n && i % 2 == 1) {
      if (nString[i + 1] == "and")
        descRes[i] = descRes[i + 2] && descRes[i];
      else {
        if (descRes[i + 2] == true) {
          alwayTrueRightIdx = i;
          break;
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    ll left, right;
    string strWantedFlag;
    cin >> left >> right >> strWantedFlag;
    bool flagWanted = (strWantedFlag == "true" ? true : false);
    if (left >= alwayTrueLeftIdx) {
      if (flagWanted == true)
        cout << 'Y';
      else
        cout << 'N';
      continue;
    }
    if (right <= alwayTrueRightIdx) {
      if (flagWanted == true)
        cout << 'Y';
      else
        cout << 'N';
      continue;
    }
    bool flagChooseTrue = true, flagChooseFalse = false;
    if (left != 1) {
      if (nString[left - 1] == "and") {
        flagChooseTrue = (ascRes[left - 2] && true);
        flagChooseFalse = (ascRes[left - 2] && false);
      } else {
        flagChooseTrue = true;
        flagChooseFalse = false;
      }
    }
    if (right != n) {
      if (nString[right + 1] == "and") {
        flagChooseTrue = flagChooseTrue && descRes[right + 2];
        flagChooseFalse = flagChooseFalse && descRes[right + 2];
      } else {
        flagChooseTrue = flagChooseTrue || descRes[right + 2];
        flagChooseFalse = flagChooseFalse || descRes[right + 2];
      }
    }
    if (flagWanted == flagChooseTrue || flagWanted == flagChooseFalse)
      cout << 'Y';
    else
      cout << 'N';
  }
  cout << endl;
  return 0;
}