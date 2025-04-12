#include <stdio.h>
#include<stdlib.h>
#include "list.h"
#include<string.h>
#include <errno.h>

typedef struct node node_t;

struct node{
    node_t *next;
    node_t *prev;
    void *item;
};

struct list{
    node_t *head;
    node_t *tail;
    int size;
};


static node_t *node_create(void *item){
    node_t *node = malloc(sizeof(node_t));
    if(node==NULL){
        return NULL;
    }
    node->item = item;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

list_t *list_create(){
    list_t *list=malloc(sizeof(list_t));
    if(list == NULL){
        fprintf(stderr,"could not create list\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size =0;
    return list;

}
void list_destroy(list_t *list){

    node_t *current = list->head;
    node_t *tmp;
    while(current != NULL){
        tmp=current;
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
    node_t *new_node = node_create(item);
    if(new_node == NULL){
        fprintf(stderr, "could not create node becouse of error: %s\n", strerror(errno));
        return -1;
    }
    if(list->head==NULL){
        list->head = new_node;
        list->tail = new_node;
        list->size++;
    }else{
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    return 0;
    
    
}


int list_addlast(list_t *list, void *item){
    node_t *new_node = node_create(item);
    if(new_node == NULL){
        fprintf(stderr, "could not create node becouse of error: %s\n", strerror(errno));
        return -1;
    }
    if(list->tail == NULL){
        list->head = new_node;
        list->tail = new_node;
    }else{
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    return 0;

}
void list_print(list_t *list){

    FILE *file = fopen("test.dot", "w");
    if(!file){
        printf("could not create file\n");
        return;
    }
    fprintf(file, "digraph doublylist {\n");
    node_t *current = list->head;
    while(current != NULL){
        if(current->next != NULL){
            fprintf(file, "%s -> %s; \n", (char *)current->item, (char *)current->next->item);
        }
        if(current->prev != NULL){
            fprintf(file, "%s -> %s; \n",(char *) current->item, (char *)current->prev->item);
        }
        current = current->next;

    }

    fprintf(file, "}\n");
    fclose(file);

}

