#include "list.h"
#include<stdio.h>



int main(){


    list_t *list = create_list();
    list_addlast(list, "four");
    list_addfirst(list, "one");
    list_addfirst(list, "Three");
    list_addfirst(list, "two");
    print_list(list, "hello.dot");
    print_l(list);

    //remove_list(list);

    return 0;
}