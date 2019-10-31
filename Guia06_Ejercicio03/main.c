#include<stdio.h>
#include<stdlib.h>


struct nodo{
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
        nuevo->sig = raiz;
        raiz=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    //La funcion funcionará mientras la pila aun tenga datos que mostrar
    while(reco!=NULL){
        //imprimimos la pila
        printf("%i ", reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

void reemplazar(struct nodo *pila, int viejo, int nuevo ){
    if(pila != NULL){
        while(pila!=NULL){
            if(pila->info == viejo){
                pila->info = nuevo;
            }
            pila = pila->sig;
        }
    }else{
        printf("No se encontró coincidencia con la pila original\n");
    }
}
int main(){
    int viejo,nuevo;
    insertar(3);
    insertar(7);
    insertar(10);
    insertar(13);
    insertar(16);
    printf("\nPila original:\n");
    imprimir();
    printf("Ingrese el numero viejo:\n");
    scanf("%d", &viejo);
    printf("Ingrese el numero nuevo:\n");
    scanf("%d", &nuevo);
    reemplazar(raiz,viejo, nuevo);
    printf("\nSe sustituyó el valor viejo = %d por el valor nuevo ingresado = %d",viejo,nuevo);
    printf("\nPila reemplazada:\n");
    imprimir();
    return 0;
}
