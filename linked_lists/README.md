# Linked Lists

### ADT:
Structure:  

- A node consists of two components: the key and the pointer to the next node
- Successive elements/nodes are connected by pointers
- The last element points to NULL
- Can grow or shrink in size during execution of a program
- Can be made just as long as required (until systems memory exhausts)
- Does not waste memory space (but takes some extra memory for pointers). It
allocates memory as list grows.

Opertaions:  

- Insert: inserts an element into the list
- Delete: removes and returns the specified position element from the list

### Advantages: 

The advantage of linked lists is that they can be expanded in constant time. To create an array, we must allocate memory for a certain number of elements. To add more elements to the array when full, we must create a new array and copy the old array into the new array. This can take a lot of time. We can prevent this by allocating lots of spaee initially but then we might allocate more than we need and waste memory. With a linked list, we can start with space for just one allocated element and add on new elements easily without the need to do any copying and reallocating.

### Disadvantages:

The main disadvantage of linked lists is access time to individual elements. Array is random-access, which means it takes O(1) to access any element in the array. Linked lists take O(n) for access to an element in the list in the worst case. Another advantage of arrays in access time is spacial locality in memory. Arrays are defined as contiguous blocks of memory, and so any array element will be physically near its neighbors. This greatly benefits from m dern CPU caching methods.



