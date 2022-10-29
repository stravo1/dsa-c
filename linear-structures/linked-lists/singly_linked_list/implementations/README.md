# Implementation of Linked Lists:
1. Stack: insertion and deletion from the same end
2. Queue: insertion and deletion from opp. ends

**Stack**  
Insertion and deletion has to be done from the same end: front or rear, but we will choose operations involving the front as the time complexity for insertion and deletion from the front (i.e., insert_first and delete_first) is O(1) (while that from the rear is O(n) or linear complexity).

**Queue**  
Insertion and deletion has to be done from opp. ends. So here we choose insertion at end and deletion from front.

> The file linked_list.c contains all the structures and functions of linked_list. It does not have any main function as it's meant to be included (copied and pasted) in other files which have the main function (here, stack.c and queue.c)
>
> `#include "linked_list.c"` will simply copy and paste contents of linked_list.c into the required file.
>
> stack.c and queue.c includes the linked_list.c file and uses the required functions

