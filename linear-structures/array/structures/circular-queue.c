/* CIRCULAR QUEUE IMPLEMENTAION  */

/* here the modulus(%) operator keeps the indexes in loop */

#include <stdio.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;

void enqueue(int x)
{
    if (front == -1) // for the first element
    {
        front = rear = 0; // initialize the array/queue
        queue[rear] = x;
        return;
    }
    if ((rear + 1) % SIZE == front) // check if full
    {
        printf("Queue full!\n");
    }
    else
    {
        rear = (rear + 1) % SIZE; // increase rear
        queue[rear] = x;          // put the element in rear
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue empty!\n");
        return -1;
    }
    int val = queue[front]; // extract the top/front element because it will be replaced by the shifting operation

    if (front == rear) // check if only one element is present
    {
        front = rear = -1; // if so then after pop the queue will be empty, so reset the array to uninitialised form
    }
    else
    {
        front = (front + 1) % SIZE; // else increase the value of front
    }
    return val;
}

void display()
{
    if (rear == -1)
    {
        printf("Queue empty!\n");
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d \t", queue[i]); // \t inserts tab
    }
    printf("%d \n", queue[rear]);
}

int main()
{
    while (1 > 0)
    {
        int inp;
        printf("\n1. Enqueue \n2. Dequeue \n3. View \n4. Exit \n\n");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
        {
            int x;
            printf("Enter number: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        }
        case 2:
        {
            printf("Dequeud element: %d \n", dequeue());
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
