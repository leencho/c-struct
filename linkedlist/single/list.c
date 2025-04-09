#include "list.h"
#include <stdio.h>
#include<stdlib.h>
#include <errno.h>
#include<string.h>
typedef struct node node_t;



struct node
{
    node_t *next;
    void *data;
};

struct iterator{
    node_t *current;
};

struct list{
    node_t *head;
    int size;
};




list_t *create_list(){
    list_t *list = malloc(sizeof(list_t));
    if(list == NULL){
        return NULL;
    }
    list->head = NULL;
    list->size =0; 
    return list;
}
void remove_list(list_t *list){

    node_t *tmp, *current;
    current=list->head;
    while((current) != NULL){
        tmp = current;
        current= current->next;
        free(tmp->data);
        free(tmp);
    }
    free(list);

}


int size_list(list_t *list){
    return list->size;
}


int list_addfirst(list_t *list, void*item){
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL){
        fprintf(stderr, "could not create node %s", strerror(errno));
        return -1;
    }

    new_node->data = item;
    new_node->next = list->head;
    list->head = new_node;

    return 1;

}





int list_addlast(list_t *list, void *item){
    node_t *new_node = malloc(sizeof(node_t));
    node_t *current;
    if(new_node == NULL){
        fprintf(stderr, "could not create node %s", strerror(errno));
        return -1;
    }
    new_node->data = item;

    if(list->head == NULL){
        new_node->next = list->head;
        list->head = new_node;
    }
    
    current=list->head;
    while( current->next != NULL){
        current= current->next;
    }
    current->next = new_node;
    new_node->next=NULL;
    

    return 1;
    
    
    
}


void print_l(list_t *list){
    node_t *current=list->head;
    while(current != NULL){
        printf("%s->", (char *)current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//add function pointer to print depending on the datatype


void print_list(list_t *list, const char *filename){
    FILE *file=fopen(filename, "wb");
    if(file == NULL){
        fprintf(stderr, "could not create file: %s, becouse of: %s\n", filename, strerror(errno));
    }
    fprintf(file, "digraph Singlylinkedlist {\n");
    fprintf(file,"node [shape=circle];\n");
    node_t *current = list->head;
    int counter=0;
    while(current != NULL ){
        fprintf(file, "node%d [label=\"%s\"];\n",counter, (char*)current->data);
        
        if(current->next != NULL){
            fprintf(file, "node%d ->node%d;\n",counter, counter+1);
  
        }else{
            fprintf(file, "node%d -> NULL;\n",counter);

        }
        current=current->next;
        counter ++;
    }



    fprintf(file, "}\n");

    fclose(file);
}



/*

void* get_element(list_t *list, int index){

}
int remove_element(list_t *list, int index){

}
int insert_element(list_t *list, void *item, int index){

}

*/



iter_t *iterator_create(list_t *list){
    iter_t *iter=malloc(sizeof(iter_t));
    if(iter==NULL) return NULL;
    iter->current = list->head;
    return iter;
}
int list_has_next(iter_t *iter){
    if(iter->current) return 1;
    return 0;
}
void *list_next(iter_t *iter){
    void *item=NULL;
    if(iter->current != NULL){
        item = iter->current->data;
        iter->current = iter->current->next;
    }

    return item;
}

