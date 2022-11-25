/////////////////////////////////////////////////////////////
//  pietCalc.cpp 
/// Calculator made to be easily 'ported' to Piet.
/// Easier in Piet to convert to RPN and then calculate.
/// Note: Does not handle multi-digit numbers, negative
///   numbers, or exponents.
/////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

//  Converts infix notation expression to reverse polish notation (RPN)
/// Params: infix - input infix expression
string infixToRPN(string infix)
{
  // Problem area in Piet... only have program stack available
  // Q: How to seperate output queue and operator stack
  string rpn = "";

  stack<string> opStack;

  // Iterate over RPN string
  for (char & c : infix)
  {
    // token being processed
    string token{c};

    // If operand
    if (isdigit(c))
    {
      // push to output
      rpn.append(token);
    }
    else if (token == "(")
    {
      opStack.push(token);
    }
    else if (token == ")")
    {
      // if right paren, pop from stack until you reach a left paren
      while (opStack.top() != "(")
      {
        rpn.append(opStack.top());
        opStack.pop();
      }
      // pop left paren
      opStack.pop();
    }
    else // operator
    {
      string o1 = token;

      // While the stack is not empty AND the top token is not a left paren
      while (!opStack.empty() && opStack.top() != "(")
      {
        string o2 = opStack.top();

        // While this is a bit messy, its how I picture it working in Piet..
        // If the precedence of the token being processed is > the top token of opStack, break
        if (o1 == "*" || o1 == "/"
          && (o2 == "+" || o2 == "-"))
        {
          break;
        }
        else // token precedence is <= top of opStack
        {
          // Push opStack operator to output
          rpn.append(opStack.top());
          opStack.pop();
        }
      }
      opStack.push(token);
    }
  }
  // Empty remaining operator stack into output
  while (!opStack.empty())
  {
    // If paren still on stack, missmatched parens - error
    if (opStack.top() == "(" || opStack.top() == ")")
    {
      return "error";
    }
    rpn.append(opStack.top());
    opStack.pop();
  }

  return rpn;
}

//  Calculates value of RPN expression
/// Params: rpn - reverse polish notation expression
int calculate(string rpn)
{
  stack<int> stack;

  // Iterate over RPN string
  for (char & c : rpn)
  {
    // If operand
    if (isdigit(c))
    {
      // Push int value
      stack.push(c - '0');
    }
    else // operator
    {
      int n1 = stack.top();
      stack.pop();
      int n2 = stack.top();
      stack.pop();

      switch (c)
      {
      case '*':
        stack.push(n2 * n1);
        break;

      case '+':
        stack.push(n2 + n1);
        break;

      case '-':
        stack.push(n2 - n1);
        break;

      case '/':
        stack.push(n2 / n1);
        break;

      default:
        cout << "Illegal operator" << endl;
        return 0;
        break;
      }
    }
  }

  return stack.top();
}

int main()
{
  // Input infix expression
  string input;
  cout << "Enter an infix expression with non-negative digits (0-9) only: " << endl;

  // Enter empty line to temrinate
  while (getline(cin, input) && !input.empty())
  {
    // Convert input to RPN
    string rpn = infixToRPN(input);
    cout << rpn << endl;

    // Calculate value of RPN
    if (rpn != "error")
    {
      int result = calculate(rpn);
      cout << " = " << result << endl;
    }
    else // error
    {
      cout << "Not a valid expression" << endl;
    }
  }
}