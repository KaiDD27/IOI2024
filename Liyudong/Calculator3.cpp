/**
 * This code snippet demonstrates the usage of the Solution class to evaluate
 * Reverse Polish Notation (RPN) expressions. The Solution class contains the
 * following methods:
 * - evalRPN: Evaluates the RPN expression using a stack and returns the result.
 * - calc: Performs the arithmetic calculation based on the given operator and
 * operands.
 * - opPriority: Returns the priority level of the given operator.
 * - calculate: Converts the infix expression to RPN and calls evalRPN to
 * evaluate the expression.
 *
 * The main function creates an instance of the Solution class and calls the
 * calculate method to evaluate different expressions.
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string> // Include the <string> header
#include <vector> // Include the <vector> header

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    for (auto token : tokens) {
      // cout << token << endl;
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        long long y = stackString.top();
        stackString.pop();
        long long x = stackString.top();
        stackString.pop();
        stackString.push(calc(x, y, token));
      } else {
        stackString.push(stoi(token)); // Replace atoi with stoi
      }
      // cout << stackString.top() << " ";
    }
    // cout << endl;
    return (int)stackString.top();
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
  // 如果不是运算符，则返回 0
  int opPriority(char c) {
    if (c == '+' || c == '-')
      return 1;
    if (c == '*' || c == '/')
      return 2;
    return 0;
  }
  int calculate(string s) {
    vector<string> tokens;
    s += " "; // 强制补了个空格在最后，则保证碰到空格就推入 tokens
    string strNum = "";
    bool needAddZero = true;
    for (auto c : s) {
      if (c == ' ') {
        if (strNum != "") {
          tokens.push_back(strNum);
          strNum = "";
        }
        continue;
      }
      if (c >= '0' && c <= '9') {
        strNum += c;
        needAddZero = false;
        continue;
      }

      if (c == '(') {
        opStack.push(c);
        needAddZero = true;
        continue;
      }

      if (c == ')') {
        needAddZero = false;
        if (strNum != "") {
          tokens.push_back(strNum);
          strNum = "";
        }
        while (opStack.top() != '(') {
          tokens.push_back(string(1, opStack.top()));
          opStack.pop();
        }
        opStack.pop();
      }

      int priLevel = opPriority(c);
      if (priLevel) {
        if (strNum != "") {
          tokens.push_back(strNum);
          strNum = "";
        }
        if ((c == '+' || c == '-') && needAddZero == true) {
          tokens.push_back("0");
        }

        if (c == '+' || c == '-' || c == '*' || c == '/')
          needAddZero = true;

        if (opStack.empty() || opStack.top() == '(') {
          opStack.push(c);
        } else {
          int priLevelStackTop = opPriority(opStack.top());
          if (priLevel > priLevelStackTop) {
            opStack.push(c);
          } else if (priLevel <= priLevelStackTop) {
            while (!opStack.empty() && priLevel <= opPriority(opStack.top())) {
              tokens.push_back(string(1, opStack.top()));
              opStack.pop();
            }
            opStack.push(c);
          }
        }
      }
    }

    while (!opStack.empty()) {
      tokens.push_back(string(1, opStack.top()));
      opStack.pop();
    }
    return evalRPN(tokens);
  }

private:
  stack<long long> stackString;
  stack<char> opStack;
};

int main() {
  Solution solution; // Instantiate an object of the Solution class
  string s;
  cin >> s;
  cout << solution.calculate(s) << endl;
}
