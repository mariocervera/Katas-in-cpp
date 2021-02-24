#include "BalancedParentheses.hpp"
#include <stack> 

static bool match(char openingChar, char closingChar) {
  return ((openingChar == '(' && closingChar == ')') ||
          (openingChar == '[' && closingChar == ']') ||
          (openingChar == '{' && closingChar == '}'));
}

static bool isOpeningCharacter(char c) {
  return (c == '(' || c == '[' || c == '{');
}

/// This function extracts the top of the stack, reducing its size by 1.
static char popFrom(stack<char> &_stack) {
  char top = _stack.top();
  _stack.pop();
  return top;
}

bool BalanceChecker::check(const string &inputStr) {
  stack<char> _stack;

  for (const char &c : inputStr) {
      if (isOpeningCharacter(c))
        _stack.push(c);
      else {
        //Closing character
        if (_stack.empty())
          return false;

        char openingChar = popFrom(_stack);
        if(!match(openingChar, c))
          return false;
      }
  }

  return _stack.empty();
}