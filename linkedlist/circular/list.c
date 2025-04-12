#include<stdio.h>
#include<stdlib.h>
#include"list.h"


typedef struct  node node_t;
struct node{
    node_t *next;
    void *item;
    
};

struct list{
    node_t *head;
    int size;
};



list_t * list_create(){

    list_t *list = malloc(sizeof(list_t));
    if(list == NULL){
        return NULL;
    }
    list->head=NULL;
    list->size=0;
    return list;

}
void list_destroy(list_t *list){
    node_t *current = list->head;
    node_t *tmp;
    while(current != NULL){
        tmp = current;
        current=current->next;
        free(tmp->item);
        free(tmp);
    }

    free(list);
}
int list_size(list_t *list){
    return list->size;
}
int list_addfirst(list_t *list, void *item){
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL){
        fprintf(stderr, "could not create node\n");
        return -1;
    }
    new_node->item = item;
    if(list->head == NULL){
         new_node->next = list->head;
         list->head = new_node;
         new_node->next = new_node;
        list->size ++;
    }else{
        node_t *tmp=list->head;
        
        while(tmp->next != list->head){
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->next = list->head;
        list->size++;
    }

    return 0;

}
int list_addlast(list_t *list, void *item){
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL){
        fprintf(stderr, "could not create node\n");
        return -1;
    }

}
void list_print(list_t *list){
    node_t *current = list->head;

    FILE *file = fopen("somefile.dot", "w");
    fprintf(file, "digraph circularlist {\n");
    do{
        
        printf("hello\n");
        fprintf(file, "%s -> %s\n", (char *)current->item, (char *)current->next->item);
        current = current->next;
        
    }while(current != list->head);
    

    fprintf(file, "}\n");
}