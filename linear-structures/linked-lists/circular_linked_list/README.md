# Circular Linked Lists

In singly linked lists and doubly linked lists, the end of lists are indicated with NULL value. But circular linked lists do not have ends. While traversing the circular linked lists we should be careful; otherwise we will be traversing the list infinitely. In circular linked lists, each node has a successor. Note that unlike singly linked lists, there is no node with NULL pointer in a circularly linked list.

> `no_tail.c` implements the circular linked list without the help of a tail pointer, thus increasing the time complexity for `insert_front()` and `delete_front()` to linear instead of constant time complexity.
>
> `tail.c` makes use of the tail pointer thus making sure time complexities of `insert_front()` and `delete_front()` remains constant.

