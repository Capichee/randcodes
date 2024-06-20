#include "list.h"

int main(){

    List * list;

    list = list_new(4);

    list_info(list);

    list_insert(list, 2);

    list_insert(list, 2);

    list_insert(list, 2);

    list_print(list);

    list_insert(list, 4);

    list_expand(list, 5);

    list_insert(list, 7);

    list_print(list);

    list_info(list);

    return 0;

}