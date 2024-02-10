#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  cout << "introduction" << endl;
  while (true) {
    string strTmp;

    cin >> strTmp;
    ///////////////////////

    cout << rand() % 4 << " " << rand() % 4 << endl;
    cout << strTmp + "!!!!" << endl;
  }
  return 0;
}