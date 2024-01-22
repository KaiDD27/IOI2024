/**
 * This code snippet represents a class named Solution. It contains several
 * member functions for evaluating Reverse Polish Notation (RPN) expressions and
 * calculating arithmetic expressions. The class has the following member
 * functions:
 * - evalRPN: This function takes a vector of strings representing RPN
 * expressions and evaluates them. It uses a stack to perform the calculations.
 * - calc: This function takes two operands and an operator as input and
 * performs the corresponding arithmetic operation.
 * - opPriority: This function takes a character representing an operator and
 * returns its priority level.
 * - calculate: This function takes a string representing an arithmetic
 * expression and converts it into RPN format. It then calls the evalRPN
 * function to evaluate the expression. The class also has two private stacks,
 * stackString and opStack, for storing operands and operators respectively.
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
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        long long y = stackString.top();
        stackString.pop();
        long long x = stackString.top();
        stackString.pop();
        stackString.push(calc(x, y, token));
      } else {
        stackString.push(stoi(token)); // Replace atoi with stoi
      }
      cout << stackString.top() << " ";
    }
    cout << endl;
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
  // 如果不是运算符，则返回 0
  int opPriority(char c) {
    if (c == '(')
      return 1;
    if (c == '+' || c == '-')
      return 2;
    if (c == '*' || c == '/')
      return 3;
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
          int priLevelStackTop = opPriority(opStack.top());
          if (priLevelStackTop < priLevel) {
            opStack.push(c);
          } else if (priLevelStackTop == priLevel) {

            tokens.push_back(string(1, opStack.top()));
            opStack.pop();
            opStack.push(c);
          } else {
            while (!opStack.empty()) {

              tokens.push_back(string(1, opStack.top()));
              opStack.pop();
            }

            opStack.push(c);
          }
        }
      } else {
        if (c >= '0' && c <= '9')
          strNum += c;
      }
    }
    // 最后一个数
    tokens.push_back(strNum);
    strNum = "";

    while (!opStack.empty()) {
      string sOp(1, opStack.top());
      tokens.push_back(sOp);
      opStack.pop();
    }
    for (auto ss : tokens) {
      cout << ss << " ";
    }
    cout << endl;
    return evalRPN(tokens);
  }

private:
  stack<long long> stackString;
  stack<char> opStack;
};

int main() {
  Solution solution; // Instantiate an object of the Solution class
  cout << solution.calculate("1+2*5/3+6/4*2")
       << endl; // Call the calculate method on the object
}
