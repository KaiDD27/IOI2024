#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;
bool choosen[8];
set<string> diffString;
string permutation = "";
void search(string &strInput) {
  if (permutation.length() == strInput.length())
    diffString.insert(permutation);
  for (int i = 0; i < strInput.length(); i++) {
    if (choosen[i] == true)
      continue;
    permutation.push_back(strInput[i]);
    choosen[i] = true;
    search(strInput);
    permutation.pop_back();
    choosen[i] = false;
  }
}

int main() {
  string strInput;
  cin >> strInput;
  search(strInput);
  cout << diffString.size() << endl;
  for (auto str : diffString) {
    cout << str << endl;
  }

  return 0;
}