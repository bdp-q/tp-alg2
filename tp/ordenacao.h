#ifndef ORDENACAO
#define ORDENACAO

/* Função que utiliza do TAD Heap para ordenar um vetor*/
void HeapSort(int vetor[],int tam, int *trocas, int *comp, int *compHeapfy, int *trocasHeapfy);

/* Função que particiona o vetor em subvetores baseado no pivô. */
void Particao(int vetor[],int esq, int dir, int *pos_pivo,int *trocas, int*comp); 

/* Função que escolhe o pivô:
- pega o primeiro, do meio e ultimo elemento do vetor e define como pivô a mediana.
*/
void EscolhePivo(int vetor[], int esq, int dir);

/* Função recursiva que ativamente realiza o QuickSort:
- checa a condição de parada; 
- chama a função de partição;
- chama a si mesma para os novos subvetores.*/
void QuickSort(int vetor[], int esq, int dir,int *trocas, int *comp);

/* Função que recebe o vetor e o ordena usando o algoritmo de Select Sort.*/
void SelectSort(int vetor[], int tam, int *trocas, int *comp);

#endif
