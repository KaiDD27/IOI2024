#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> abc(26);
int main() {
  string strIn;
  cin >> strIn;
  for (int i = 0; i < strIn.length(); i++) {
    abc[strIn[i] - 'A']++;
  }
  string strOut = "";
  char oddChar = '0';
  for (int i = 0; i < 26; i++) {
    if (abc[i] % 2 == 0) {
      strOut.append(abc[i] / 2, i + 'A');
    } else {
      if (oddChar != '0') { // 如果已经有一个字符出现奇数次，那么无解
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      oddChar = i + 'A';
      strOut.append(abc[i] / 2, i + 'A');
    }
  }
  string strOutRev = strOut; // 创建一个反向字符串
  reverse(strOutRev.begin(), strOutRev.end());
  if (oddChar)
    strOut += oddChar; // 如果有字符出现奇数次，将它放在中间
  strOut += strOutRev; // 添加反向字符串
  cout << strOut << endl;
  return 0;
}