#include <stdio.h>
#include "heap.h"

/* Função auxiliar que pega um string e copia para outro*/
void CopiaString(char *destino, const char *origem) {
    int i = 0;
    while (origem[i] != '\0'){
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; 
}

void InicHeap(struct paciente *heap, int *tam, int tammax) {
    int i;

    *tam = 0; 

	/*reseta todos os elementos*/
    for (i = 0; i < tammax; i++) {
        heap[i].nome[0] = '\0';
        heap[i].prioridade = 0;
    }
}

/*funcao auxiliar para o heapfy que ...*/
void InsereHeapEF(struct paciente *heap, int tam){
	struct paciente aux;
	int i=tam;

	while (i>1 && heap[i/2].prioridade < heap[i].prioridade){
		aux = heap[i/2];
		heap[i/2] = heap[i];
		heap[i] = aux;
		i = i/2;
	}

}

void ImprimeHeap(struct paciente *heap, int tam){
	int i;

	/*se a fila eh vazia*/	
	if (tam == 0){
		printf("Heap Vazia\n");
		return;
	}

	printf("Heap de Pacientes: ");
	for (i=1; i<=tam; i++)
		printf("(nome: %s | prio: %d) ", heap[i].nome, heap[i].prioridade);
	printf("\n");
}

void InsereHeap(struct paciente *heap, int *tam, int prio, char *nome){
	struct paciente novo;

	/*cria novo paciente*/
    CopiaString(novo.nome, nome);
	novo.prioridade = prio;

	/*adiciona no final e heapifica*/
	(*tam)++;
	heap[*tam] = novo;
	InsereHeapEF(heap, *tam); 

    return;
}

int RemoveHeap(struct paciente *heap, int *tam){

	if (*tam == 0)
		return 0;

	/*o removido recebe o valor do ultimo elemento da heap*/
	heap[1] = heap[*tam];
	(*tam)--;
    if (!ChecaHeap(heap,*tam)){
        Heapfy(heap, *tam, 1);
    }
	return 1;
}

/* Função auxiliar que pega dois strings e compara um com o outro para ver se são iguais */
int ComparaString(const char *string1, const char *string2){
    while (*string1 == *string2 ){
        string1++;
        string2++;
    }
    return string1 - string2;
}
/* Função auxiliar para a Alteraheap que encontra o indice do paciente no vetor */
int AchaPaciente(struct paciente *heap, int tam, int prio, char *nome){
	int i=1;

	/*itera ate a heap acabar ou achar o elemento*/
	while (i <= tam){
		if (ComparaString(heap[i].nome,nome) && heap[i].prioridade == prio)
			return i;
		i++;
	}


	return -1;
}

int AlteraHeap(struct paciente *heap, int tam, int prio, int nova_prio, char *nome){
	int pos = AchaPaciente(heap, tam, prio, nome);

	/*elemento nao existe*/
	if (pos == -1)
		return 0;

	/*atualiza prioridade*/
	heap[pos].prioridade = nova_prio;
    if (!ChecaHeap(heap,tam))
	    Heapfy(heap, tam, 1);
	
    return 1;
}

int ChecaHeap(struct paciente *heap, int tam){
    int i;

    for (i=tam; i>1; i--)
    	if (i/2 >= 1 && heap[i].prioridade > heap[i/2].prioridade)
    		return 0;

    return 1;
}

void Heapfy(struct paciente *heap, int tam, int i) {
    int maior = i;             
    int esq = 2 * i;            
    int dir = 2 * i + 1;        
    struct paciente aux;        

    /*se o elemento esquerdo existe e é maior que o atual*/
    if (esq <= tam && heap[esq].prioridade > heap[maior].prioridade)
        maior = esq;

    /*se o elemento direito existe e é maior que o atual*/
    if (dir <= tam && heap[dir].prioridade > heap[maior].prioridade)
        maior = dir;

    /*se atual não eh o maior, troca e chama o heapfy denovo*/
    if (maior != i) {
        aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        Heapfy(heap, tam, maior);  
    }
}

void SacodeHeap(int vetor[],int tam,int *trocas,int *comp){
    int aux;
    int i = 2;
    while (i <= tam){
        (*comp)++;
        if ((i < tam) && (vetor[i] < vetor[i+1]))
            i++;
        (*comp)++;
        if (vetor[i/2] >= vetor[i]) 
            return;
        (*trocas)++;
        aux = vetor[i/2];
        vetor[i/2] = vetor[i];
        vetor[i] = aux;
        i = i * 2;
    }
}