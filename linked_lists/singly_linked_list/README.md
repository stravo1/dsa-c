# Singly Linked Lists

Generally “linked list” means a singly linked list. This list consists of a number of nodes in which each node has only one next pointer to the following element. The link of the last node in the list is NULL, which indicates the end of the list. Once we go to the next node we can't go back to the previous node.

> - separate.c: has 3 separate functions for insertion (`insert_first, insert_pos, insert_end`). Similarly we have 3 different functions for deletion.
> - unified.c: has a single `insert` and a single `delete` function which takes position as a parameter (`void insert(int k, int pos){...}` and `int delete(int pos){...}`)

