#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int tamanho;
    int elementos[MAX];
}Lista;

void iniciaLista(Lista * lista){
    lista->tamanho = 0;
}

int insereElemento(Lista * lista, int num){
    if(lista->tamanho < MAX){
        lista->elementos[lista->tamanho] = num;
        lista->tamanho++;
        return 1;
    }
    else{
        return 0;
    }
}

int removeElemento(Lista * lista, int posicao){
    if(lista->tamanho > 0 && posicao <= lista->tamanho){
        int i = 0, aux = 0;
            for(i = posicao; i<lista->tamanho-1; i++){
                lista->elementos[i] = lista->elementos[i+1];
            }
            lista->tamanho--;
            return 1;
    }
    else{
        return 0;
    }
}

int buscaElemento(Lista * lista, int elemento){
    int i = 0;
    for(i=0;i<lista->tamanho; i++){
        if(lista->elementos[i]==elemento){
            return i;
        }
    }
    return -1;
}

void printElemento(Lista * lista){
    for(int i=0; i<lista->tamanho; i++){
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void concatenaLista(Lista * lista1, Lista * lista2, Lista * lista3){
    if(lista1->tamanho+lista2->tamanho > MAX){
        printf("Erro: Tamanho total excedente\n");
        exit(1);
    }
    lista3->tamanho = lista2->tamanho + lista1->tamanho;
    int i, j, aux = 0;
    for(i=0;i<lista1->tamanho; i++){
        lista3->elementos[i] = lista1->elementos[i];
    }
    for(i=lista1->tamanho;i<lista3->tamanho;i++){
        lista3->elementos[i] = lista2->elementos[aux];
        aux++;
    }
}

int main(){
    Lista minhaLista;
    Lista minhaLista2;
    Lista minhaLista3;

    iniciaLista(&minhaLista);
    insereElemento(&minhaLista, 10);
    insereElemento(&minhaLista, 5);
    insereElemento(&minhaLista, 50);

    iniciaLista(&minhaLista2);
    insereElemento(&minhaLista2, 18);
    insereElemento(&minhaLista2, 13);
    insereElemento(&minhaLista2, 2);

    iniciaLista(&minhaLista3);
    concatenaLista(&minhaLista, &minhaLista2, &minhaLista3);

    printElemento(&minhaLista3);
}