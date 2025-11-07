#include <stdio.h>
#include "heap.h"
#include "ordenacao.h"


void InsereHeapV(int vetor[],int tam,int *trocas,int *comp){
    int aux;
    int i = tam;
    (*comp)++;
    while ((i > 1) && (vetor[i/2] < vetor[i])){
        (*trocas)++;
        aux = vetor[i/2];
        vetor[i/2] = vetor[i];
        vetor[i] = aux;
        i = i/2;
    }
}

void HeapfyV(int vetor[], int tam,int *trocas,int *comp) {
    int i;
    for (i = 1; i < tam; i++){
        InsereHeapV(vetor,i,trocas,comp);
    }
}

void HeapSort(int vetor[],int tam, int *trocas, int *comp){
    int aux;
    HeapfyV(vetor,tam,trocas,comp);
    /* pega o primeiro elemento do Heap e coloca na ultima posição*/
    for (int i = tam; i > 1; i--){
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        (*trocas)++;
        SacodeHeap(vetor,i-1,trocas,comp);
    }
}

void Particao(int vetor[],int esq, int dir, int *pos_pivo,int *trocas, int*comp){
    int aux;
    int i = esq;
    int j = dir;
    int pivo = vetor[esq];

    while (i < j){
        while((vetor[i] <= pivo) && (i < dir)){
           (*comp)++;
            i++;
        }
        while ((vetor[j] > pivo)){
            (*comp)++;
            j--;
        }
        if (i < j){
           (*trocas)++;
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;

        }
    }
    aux = vetor[j];
    vetor[j] = vetor[esq];
    vetor[esq] = aux;
    *pos_pivo = j;
   (*trocas)++;
}

void EscolhePivo(int vetor[], int esq, int dir){
    int aux;
    int meio = (esq + dir)/2;

    if (vetor[esq] > vetor[meio]) {
        aux = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = aux;
    }
    if (vetor[esq] > vetor[dir]) {
        aux = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux;
    }

    if (vetor[meio] > vetor[dir]) {
        aux = vetor[meio];
        vetor[meio] = vetor[dir];
        vetor[dir] = aux;
    }
    /* coloca na esquerda a mediana */
    aux = vetor[meio]; 
    vetor[meio] = vetor[esq]; 
    vetor[esq] = aux;
}

void QuickSort(int vetor[], int esq, int dir,int *trocas, int *comp){
    int pos_pivo;
    if (esq < dir){
        EscolhePivo(vetor,esq,dir);
        Particao(vetor,esq,dir,&pos_pivo,trocas,comp);
        QuickSort(vetor,esq,pos_pivo - 1,trocas,comp);
        QuickSort(vetor,pos_pivo + 1,dir,trocas,comp);
    }
}

void SelectSort(int vetor[], int tam, int *trocas,int *comp){ 
	int aux;
	int menor;

	for (int i = 1; i < tam; i++)
	{
		menor = i;
		for (int j = i + 1; j <= tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
            (*comp)++;
        }
        aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux;
        (*trocas)++;
	}
}