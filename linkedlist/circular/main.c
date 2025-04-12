#include "list.h"
#include <stdio.h>

int main(){
    printf("list");
    list_t *list = list_create();
    
    
    if(list==NULL){
        fprintf(stderr, "could not create list\n");
        return -1;
    }
    

    list_addfirst(list, "one");
    list_addfirst(list, "two");
    list_addfirst(list, "three");
    list_addfirst(list, "four");
    list_print(list);
    return 0;
}

