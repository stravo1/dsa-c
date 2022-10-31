/* NO STORAGE WASTE aka SHIFTING OPERATION IMPLEMENTAION OF QUEUE */

#include <stdio.h>
#define SIZE 10

int queue[SIZE], rear = -1;

void enqueue(int x)
{
	if (rear == SIZE - 1)
	{
		printf("Queue full!\n");
		return;
	}
	queue[++rear] = x; // increase rear by 1 and then put the new element there
}

int dequeue()
{
	if (rear == -1)
	{
		printf("Queue empty!\n");
		return -1;
	}
	int val = queue[0]; // extract the top/front element because it will be replaced by the shifting operation
	for (int i = 0; i <= rear; i++)
	{
		queue[i] = queue[i + 1]; // shifting operation => prev element = next element
	}
	rear--; // decrease rear by 1
	return val;
}

void display()
{
	if (rear == -1)
	{
		printf("Queue empty!\n");
		return;
	}
	for (int i = 0; i <= rear; i++)
	{
		printf("%d \t", queue[i]); // \t inserts tab
	}
	printf("\n");
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
