#ifndef _LIST_H_
#define _LIST_H_

typedef struct list list_t;

list_t * list_create();
void list_destroy(list_t *list);
int list_size(list_t *list);
int list_addfirst(list_t *list, void *item);
int list_addlast(list_t *list, void *item);
void list_print(list_t *list);

#endif