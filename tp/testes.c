/* perguntar ao professor sobre nome do arquivo + como deve ser a interface (coloca literalmente
as operações ou coloca do jeito que um nao programador entenderia?)*/
/*da pra perguntar pro professor se ele prefere a gente fazendo com .c e com .h,
se é de livre escolha, ou se ele prefere num arquivo só*/
/*a enfermeira deve poder checar se é heap e deve fazer o heapfy ou 
o programa deveria fazer isso automaticamente?*/
/* Colocar apenas o valor de prioridade ou tem que ser uma struct? pra ter um nome? H: Como o enunciado pede nome, acho que struct.*/

/* vetor de número aleatorios, pode ser negativo? posso colocar um min e max?*/
/* precisa imprimir o vetor de 1024 elementos? não né*/
/* não precisa checar se ordenou direito? ok né ...*/

/* Haico, eu bote o padrão do código da maneira que o professor faz em sala,
pq eu tenho certeza que ele vai gostar, mas podemos mudar se vc achar melhor!*/


/* --------------------------------------------------------------------------------------
   Programa que implementa o Tipo Abstrato de Dados Heap,
   além dos algoritmos de ordenação Quick e Select Sort.
   Objetivo: Aprender a implementação do Heap e comparar ele com o Quick e Select sort
   Restricoes: o programa assuma que o usuario entrou com os valores corretos, inteiros.

   Autores: Breno Demio Padilha e Haico de Toledo Boehs 
   Disciplina: Algoritmos II
   Data da ultima atualizacao: 2025/2
----------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_V 1024

//como nao temos definido se precisa da struct pro nome, vou supor que precisa.
struct paciente {
	int prioridade;
	char *nome;
};

void InicHeap(struct paciente *heap, int *tam, int tammax) {
    int i;

    *tam = 0; 

    for (i = 0; i < tammax; i++) {
        heap[i].nome = NULL;
        heap[i].prioridade = 0;
    }
}


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

//tem que melhorar
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




void InsereHeap(struct paciente *heap, int *tam, int prio, char *nome){
	struct paciente novo;
	
	/*cria novo paciente*/
	novo.nome = nome;
	novo.prioridade = prio;
	
	/*adiciona no final e heapifica*/
	(*tam)++;
	heap[*tam] = novo;
	InsereHeapEF(heap, *tam); 
	
    return;
}


void ImprimeHeap(struct paciente *heap, int tam){
	int i;
	
	if (tam == 0){
		printf("Heap Vazia\n");
		return;
	}
	
	printf("Heap de Pacientes: ");
	for (i=1; i<=tam; i++)
		printf("(nome: %s | prio: %d) ", heap[i].nome, heap[i].prioridade);
	printf("\n");
}


int AchaPaciente(struct paciente *heap, int tam, int prio, char *nome){
	int i=1;
	
	/*itera ate a heap acabar ou achar o elemento*/
	while (i <= tam){
		if (heap[i].nome == nome && heap[i].prioridade == prio)
			return i;
		i++;
	}
	

	return -1;
}


int RemoveHeap(struct paciente *heap, int *tam){

	if (*tam == 0)
		return 0;
	
	/*o removido recebe o valor do ultimo elemento da heap*/
	heap[1] = heap[*tam];
	(*tam)--;
	Heapfy(heap, *tam, 1);
	
	return 1;
}


int AlteraHeap(struct paciente *heap, int tam, int prio, int novaprio, char *nome){
	int pos = AchaPaciente(heap, tam, prio, nome);
	
	/*erro se o elemento nao existe*/
	if (pos == -1)
		return 0;
	
	/*atualiza prioridade*/
	heap[pos].prioridade = novaprio;
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


int main (){
	struct paciente heap[TAM_V];
	int tam = 0;
	char *name = "raku";
	
	InicHeap(heap, &tam, TAM_V);
	
	InsereHeap(heap, &tam, 10, name);
	InsereHeap(heap, &tam, 1, name);
	InsereHeap(heap, &tam, 4, name);
	InsereHeap(heap, &tam, 17, name);
	InsereHeap(heap, &tam, 0, name);
	InsereHeap(heap, &tam, 9, name);
	InsereHeap(heap, &tam, 2, name);
	InsereHeap(heap, &tam, 3, name);
	
	RemoveHeap(heap, &tam);
	RemoveHeap(heap, &tam);

	AlteraHeap(heap, tam, 17, 4, "raku");
	ImprimeHeap(heap, tam);
	

	
	if (ChecaHeap(heap, tam))
		printf("eh heap\n");
	else
		printf("nao eh heap\n");
	
	
		
}


























