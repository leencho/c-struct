

//compare and exchange function
#ifndef __LIST__H_
#define __LIST_H_

typedef struct list list_t;
typedef struct iterator iter_t;
list_t *create_list();
void remove_list(list_t *list);
int size_list(list_t *list);
int list_addfirst(list_t *list, void *item);
int list_addlast(list_t *list, void *item);
void print_list(list_t *list, const char *filename);
void print_l(list_t *list);

iter_t *iterator_create(list_t *list);
int list_has_next(iter_t *iter);
void *list_next(iter_t *iter);


#endif
