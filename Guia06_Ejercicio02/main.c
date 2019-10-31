#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int info;
    struct nodo *sig;
};
struct nodo2{
    int info;
    struct nodo2 *sig;
};

struct nodo *raiz=NULL;
struct nodo2 *raiz2=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}
void insertar2(int x){
    struct nodo2 *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz2==NULL){
        raiz2=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz2;
        raiz2=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    printf("Pila original.\n");
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}
void imprimirInvertido(){
    struct nodo2 *reco=raiz2;
    printf("Pila invertida.\n");
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int invertir(){
    if(raiz!=NULL){
        while (raiz!=NULL){
            struct nodo *bor=raiz;
            insertar2(bor->info);
            raiz=raiz->sig;
            free(bor);
        }
    } else{
        return -1;
    }
}

int main() {
    insertar(10);
    insertar(20);
    insertar(40);
    imprimir();
    invertir();
    imprimirInvertido();
    return 0;
}