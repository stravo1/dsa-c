#include <stdio.h>
#define SIZE 10

int stack[SIZE], top = -1;

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("Stack full!\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack empty!\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack empty!\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d \t", stack[i]);
    }
}

int main()
{
    while (1 > 0)
    {
        int inp;
        printf("\n1. Push \n2. Pop \n3. View \n4. Exit \n\n");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
        {
            int x;
            printf("Enter number: ");
            scanf("%d", &x);
            push(x);
            break;
        }
        case 2:
        {
            printf("Popped element: %d \n", pop());
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            return 0;
        default:
        {
            printf("Wrong choice, choose again: \n");
            break;
        }
        }
    }
}
