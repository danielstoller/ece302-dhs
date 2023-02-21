#include <string>
using std::string;
#include <stack>;
using std::stack;


#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"


bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  //Error checking
  if ((first > last)) {
    return -1;
  }

  //Ch is the last thing in the imported string
  char ch = s[last];
  //Situation that ends the recursive function 
  if (isalpha(ch)) {
    //Returns the index to the first number,
    //With the imported index being decremented
    return last;
  } 
  else {
    if (isoperator(ch)) {
      //If the element was an operator
      //Recursively call with index-1
      int lastEnd = endPost(s, last - 1);

      //Error check
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } 
    //Error check
    else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}


//In this function, we need to reverse the places of all the operators in the string
//But we need to keep the order of the numbers
void convert(string &postfix, string &prefix) {
  int last = postfix.size()-1;

  if(isalpha(postfix[last]))
    //If the last char is a number, append it on the front
    prefix = postfix[last] + prefix;
  else
  {
    //For the operator to be appended to prefix, it must get through convert with size-1 and size-2
    //This will be passed immediately if there are 2 numbers in a row before the operand
    
    //Save the last operator
    char operand = postfix[last];

    //Pop off the last char
    if(!postfix.empty())
      postfix.pop_back();
    //Send postfix-1 through the same function
    convert(postfix, prefix);

    //Pop off a second char
    if(!postfix.empty())
      postfix.pop_back();
    //Send postfix-2 through the same
    convert(postfix, prefix);

    prefix = operand + prefix;
  }
}
