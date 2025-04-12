
#include "list.h"


int main(){

    list_t *list = list_create();
    list_addfirst(list, "one");
    list_addfirst(list, "two");
    list_addlast(list, "ten");
    list_addfirst(list, "four");
    list_addlast(list, "three");
    list_print(list);

    return 0;
}