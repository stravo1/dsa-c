#include "stack.c"
#define MAX 100

enum priority { LOW, SAME, HIGH, ERROR };

enum priority getPriority(char operator1,
                          char operator2) { // compare operator1 with operator2
  if (operator1 == '^') {                   // exponent has highest priority

    return HIGH;
  }
  if ((operator1 == '*' || operator1 == '/')) {
    if ((operator2 == '*' || operator2 == '/')) {
      return SAME;
    } else if ((operator2 == '+' ||
                operator2 == '-')) { // 2nd operator is '+' or '-'

      return HIGH;
    }
  }
  if ((operator1 == '+' || operator1 == '-')) {
    if ((operator2 == '*' || operator2 == '/')) {
      return LOW;
    } else if ((operator2 == '+' ||
                operator2 == '-')) { // 2nd operator is '+' or '-'

      return SAME;
    }
  }
  // printf("err %c %c \n", operator1, operator2);
  return ERROR;
}

int isDigit(char c) { // to check whether the char is a digit or not
  if (c >= '0' && c <= '9')
    return 1;
  return 0;
}

void convert(char c) {

  if (c == '\0') {      // if we reach the end of the expr
    while (top != -1) { // empty stack
      printf("%c", pop());
    }
    return;
  }
  if (isDigit(c)) { // if an operand, print it
    printf("%c", c);
    return;
  }

  if (top == -1 ||
      peek() ==
          '(') { // if stack is empty or incoming char is '(', push to stack
    // printf("PUSHING CHAR %c\n", c);
    push(c);
    return;
  }

  if (c == ')') { // if ')' is encountered, keep on popping until a '(' is found
    while (1) {
      char temp = pop();
      if (temp == '(') {
        break;
      } else {
        printf("%c", temp);
      }
    }
    return;
  }

  if (getPriority(c, peek()) ==
      HIGH) { // if incoming operator has higher precedence than the top
    // printf("PUSHING CHAR %c\n", c);
    push(c); // push the operand
    return;
  }

  if (getPriority(c, peek()) == LOW ||
      getPriority(c, peek()) ==
          SAME) // if incoming operator has lower precedence than the top
  {
    printf("%c", pop()); // pop and print the top of stack
    // printf("%d d\n", top);
    convert(c); // if higher precedence, push
    return;
  }

  printf("ERROR %c\n", c);
  return;
}

int main() {

  char exp[MAX]; // make an character array of size MAX

  printf("\n\n!! This program supports only SINGLE digit values and basic "
         "operations !!\n\n");
  printf("Enter expression: ");
  scanf("%[^\n]", exp); // get the expression from the user

  int count = 0;
  printf("Postfix expression is: ");
  while (1) {
    char c = exp[count];
    if (c == '\0') {
      convert(c);
      break;
    }
    convert(c);
    count++;
  }
  printf("\n\n");
}
