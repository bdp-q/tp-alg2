#ifndef HEAP
#define HEAP

/* Struct utilizada para definir um paciente:
- possui uma int com sua prioridade na fila
- possui um nome */
struct paciente {
	int prioridade;
	char nome[100];
};
/* Inicializa o Heap zerando todos os elementos do vetor */
void InicHeap(struct paciente *heap, int *tam, int tammax);


/* Insere o paciente na fila de prioridades */
void InsereHeap(struct paciente *heap, int *tam, int prio, char *nome);

/* Remove a primeira pessoa na fila de prioridades:
- retorna 1 se conseguiu e 0 se o vetor está vazio */
int RemoveHeap(struct paciente *heap, int *tam);

/* Imprime o Heap na ordem da fila real de pacientes */
void ImprimeHeap(struct paciente *heap, int tam);

/* Altera a prioridade de algum paciente presente na fila
- retorna 1 se deu certo e 0 se não encontrou o paciente para trocá-lo */
int AlteraHeap(struct paciente *heap, int tam, int prio, int novaprio, char *nome);


/* Checa se um vetor é Heap ou não:
- retorna 1 se for Heap e 0 se não for */
int ChecaHeap(struct paciente *heap, int tam);

/* Transforma um vetor em Heap */
void Heapfy(struct paciente *heap, int tam, int i);

/* Função que reorganiza o Heap após apenas seu primeiro elemento estar errado*/
void SacodeHeap(int vetor[],int tam,int *trocas, int *comp); 

#endif