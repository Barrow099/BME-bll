Test C implemetation of a Linked List. Stores data as void pointers.

WARNING! Test implementation. Use at your own risk.

Usage: include bll.h, add bll.c to your project

Functions:

bll_create(): Creates an empty bll list and returns a pointer to it.
bll_delete(bll_list*): deletes a bll list, frees the allocated memory.
bll_add(bll_list*,void* data): Adds data to the list
bll_get(bll_list*, int index): Returns the index'th element of the list. Returns 0 if out of bounds.
bll_remove(bll_list*, int index): Removes the index'th element of the list. Removes nothing if out of bounds.
