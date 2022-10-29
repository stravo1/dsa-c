#include "linked_list.c"

void bubble()
{
    if (!head)
    {
        printf("Linked list has not yet been initialized\n");
        return -1;
    }
    int flag = 1;
    int i;
    for (i = 0; i < len; i++)
    {
        flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            node *n = head;
            for (int k = 0; k < j; k++)
            {
                n = n->next;
            }
            if (n->key > n->next->key)
            {
                int t = n->key;
                n->key = n->next->key;
                n->next->key = t;
                flag = 1;
            }
        }
    }
}

int main()
{

    while (1 > 0)
    {
        int i;
        printf("1. Insert \n2. Display \n3. Delete\n4. Sort\n5. Exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            printf("1. Front\n2. Middle\n3. End\n");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
            {
                printf("Enter key: ");
                scanf("%d", &i);
                insert_first(i);
                break;
            }
            case 2:
            {
                int k, pos;
                printf("Enter key: ");
                scanf("%d", &k);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(k, pos);
                break;
            }
            case 3:
            {
                printf("Enter key: ");
                scanf("%d", &i);
                insert_end(i);
                break;
            }
            default:
                printf("Choose again\n");
            }
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            printf("1. Front\n2. Middle\n3. End\n");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
            {
                delete_first();
                break;
            }
            case 2:
            {
                int pos;
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            }
            case 3:
            {
                delete_last();
                break;
            }
            default:
                printf("Choose again\n");
            }
            break;
        }
        case 4:
        {
            bubble();
            break;
        }
        case 5:
            exit(1);
        default:
            printf("Choose again\n");
        }
    }
}
