#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List * list_new(int size){
    List * L = NULL;
    L = (List*)calloc(1,sizeof(List));
    L->n = 0;
    L->e = (int*)calloc(size, sizeof(int));
    L->size = size;
    return L;
}

void list_info(List * L){
    printf("Tamanho máximo %d\n", L->size);
    printf("Quantidade de elementos %d\n", L->n);
    printf("Ponteiro do vetor: %d\n", L->e);
}

void list_remove(List * L, int pos){
    
}

void list_reduce(List * L){

}

void list_free(List * L){
    free(L->e);
    free(L);
}

void list_insert(List * L, int v){
    if(L->n < L->size){
        L->e[L->n] = v;
        (L->n)++;
    }
}


void list_print(List * L){
    int i;
    printf("[");
    for(i=0;i<L->n;i++){
        printf("%d, ", L->e[i]);
    }
    printf("]\n");
}

void list_expand(List * L, int new_size){
    L->e = realloc(L->e, sizeof(int)*new_size);
    L->size = new_size;
}