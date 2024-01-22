#include <algorithm>
#include <stack>
#include <string> // Include the <string> header
#include <vector> // Include the <vector> header

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    for (auto token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        long long y = stackString.top();
        stackString.pop();
        long long x = stackString.top();
        stackString.pop();
        stackString.push(calc(x, y, token));
      } else {
        stackString.push(stoi(token)); // Replace atoi with stoi
      }
    }
    return stackString.top();
  }
  long long calc(long long x, long long y, string &token) {
    if (token == "+")
      return x + y;
    if (token == "-")
      return x - y;
    if (token == "*")
      return x * y;
    if (token == "/")
      return x / y;

    return 0; // Add a default return statement
  }

  int opPriority(char c) {
    if (c == '+' || c == '-')
      return 1;
    if (c == '*' || c == '/')
      return 2;
    return 0;
  }
  int calculate(string s) {
    vector<string> tokens;
    string strNum = "";
    for (auto c : s) {
      int priLevel = opPriority(c);
      if (priLevel) {
        tokens.push_back(strNum);
        strNum = "";
        if (opStack.empty()) {
          opStack.push(c);
        } else {
          if (opPriority(opStack.top()) < priLevel) {
            opStack.push(c);
          } else {
            string sOp(1, opStack.top());
            tokens.push_back(sOp);
            opStack.pop();
            opStack.push(c);
          }
        }
      } else {
        if (c != ' ')
          strNum += c;
      }
    }
    tokens.push_back(strNum);
    strNum = "";

    if (!opStack.empty()) {
      string sOp(1, opStack.top());
      tokens.push_back(sOp);
      opStack.pop();
    } else {
      // error
    }

    return evalRPN(tokens);
  }

private:
  stack<long long> stackString;
  stack<char> opStack;
};