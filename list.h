#ifndef __list_h__
#define __list_h__

typedef struct{
    int n;
    int * e;
    int size;
}List;

List * list_new(int size);
void list_free(List * L);
void list_insert(List * L, int v);
void list_print(List * L);
void list_expand(List * L,  int n);
void list_info(List * L);
void list_remove(List * L, int pos);
void list_reduce(List * L);

#endif