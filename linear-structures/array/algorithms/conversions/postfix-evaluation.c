#include "stack.c" // include the stack file
#define MAX 100 // max size of expression

int isDigit(char c) { // to check whether the char is a digit or not
  if (c >= '0' && c <= '9')
    return 1;
  return 0;
}

int operate(char operator, int operand1, int operand2) { // perform the operation
  switch (operator) {
  case '+':
    return (operand1 + operand2);
  case '-':
    return (operand1 - operand2);
  case '*':
    return (operand1 * operand2);
  case '/':
    return (operand1 / operand2);
  default:
    printf("ERROR!\nPlease try again!\n");
    return -1;
  }
}

int eval(char exp[]) {                   // take in the postfix expression
  for (int i = 0; exp[i] != '\0'; i++) { // traverse the string
    char c = exp[i];                     // pick thr next character

    if (c == ' ') // ignore spaces
      continue;
    if (isDigit(c) == 1) { // if the character is a digit
      push(c - '0');       // push the numeric value of the digit/character
    } else {               // if chatacter is an operator

      char operator= c;     // get the operator
      int operand1 = pop(); // get the 1st operand
      int operand2 = pop(); // get the 2nd operand

      // perform the operation and get the new value
      int val = operate(operator, operand1, operand2);
      push(val); // push the new value to stack
    }
  }
  int result =
      pop(); // at the end there is just one value in the stack => the result
  return result;
}

int main() {

  char exp[MAX]; // make an character array of size MAX

  printf("!! This program supports only SINGLE digit values and basic operations !!\n");
  printf("Enter expression\n");
  scanf("%[^\n]", exp); // get the expression from the user

  printf("%d\n", eval(exp)); // print the result
}
