#include <climits>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> mpShock;

int calcShock(int val) {
  string strVal = to_string(val);
  int ret = 0;
  for (int i = 0; i < strVal.length(); i++) {
    ret += mpShock[strVal[i]];
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  // 用map来存 char 对应的 hurt
  for (int i = 0; i < 10; i++) {
    cin >> mpShock['0' + i];
  }

  cin >> mpShock['+'];
  cin >> mpShock['*'];
  cin >> mpShock['='];

  int miniHurt = INT_MAX;
  for (int i = 1; i <= n; i++) {
    // 先计算直接输入数字的 hurt，比如 10 就是 1,0 这两个字符 hurt 之和
    int iShock = calcShock(i);
    // 在计算采用乘法得到数字的 hurt，并和之前的结果取 min，比如 10 可以等于 2*5
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        iShock = min(iShock, calcShock(j) + calcShock(i / j) + mpShock['*']);
      }
    }
    // 最后计算加上另一个数等于n，只需考虑直接输入数字，因为之前包含了用了一次乘号的可能。
    if (i != n)
      iShock += calcShock(n - i) + mpShock['+'];
    miniHurt = min(miniHurt, iShock);
  }
  cout << miniHurt + mpShock['='] << endl;
  return 0;
}
