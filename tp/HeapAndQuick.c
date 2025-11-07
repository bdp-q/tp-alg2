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


struct paciente {
	int prioridade;
	char *nome;
};


void InicHeap(struct paciente *heap, int *tam, int tammax) {
    int i;

    *tam = 0; 
	
	/*reseta todos os elementos*/
    for (i = 0; i < tammax; i++) {
        heap[i].nome = NULL;
        heap[i].prioridade = 0;
    }
}


/*funcao auxiliar para o heapfy*/
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

/*auxiliar para a alteraheap*/
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
	
	/*elemento nao existe*/
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


void Heapsort(){
    puts("ordena em Heap");
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
    int mediana = (esq + dir)/2;

    if (vetor[esq] > vetor[mediana]) {
        aux = vetor[esq];
        vetor[esq] = vetor[mediana];
        vetor[mediana] = aux;
    }
    if (vetor[esq] > vetor[dir]) {
        aux = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux;
    }

    if (vetor[mediana] > vetor[dir]) {
        aux = vetor[mediana];
        vetor[mediana] = vetor[dir];
        vetor[dir] = aux;
    }
    aux = vetor[mediana]; 
    vetor[mediana] = vetor[esq]; 
    vetor[esq] = aux; //colocamos a mediana dos 3 valores checados no vetor esq 
}

void QuickSort(int vetor[], int esq, int dir,int *trocas, int *comp){ //talvez criar uma funcao pra selecao do pivo? nao sei
    int pos_pivo;
    if (esq < dir){
        EscolhePivo(vetor,esq,dir);
        Particao(vetor,esq,dir,&pos_pivo,trocas,comp);
        QuickSort(vetor,esq,pos_pivo - 1,trocas,comp);
        QuickSort(vetor,pos_pivo + 1,dir,trocas,comp);
    }
}

void SelectSort(int vetor[], int tam){ 
	int temp;
	int menor;
    int trocas = 0;
    int comp = 0;

	for (int i = 0; i < tam-1; i++)
	{
		menor = i;
		for (int j = i + 1; j < tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
            comp++;
        }
        if (menor != i){
            temp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = temp;
            trocas++;
        }
	}

    printf("comparacoes: %d ", comp);
    printf("trocas: %d", trocas);
	return;
}

void GeraVetorAleat(int vetor[]){ // essa funcao cria o vetor de números aleatórios com 1024 elementos
    srand(time(NULL));
    for (int i = 0; i < TAM_V; i++)
    {
        vetor[i] = rand() % 100;
   //     printf("%d ",vetor[i]);
    }
    puts("criou o vetor aleatorio!");

}

void ComparaAlg(){ 
    int vetor[TAM_V];
    int trocas_quick = 0;
    int comp_quick = 0;
    puts("trocas e comparações do HeapSort:");

    puts("trocas e comparações do  QuickSort:");
    GeraVetorAleat(vetor); //tem problema fazer assim?
    QuickSort(vetor,0,TAM_V-1,&trocas_quick,&comp_quick);
    printf("comparacoes: %d ", comp_quick);
    printf("trocas: %d\n", trocas_quick);
    puts("trocas e comparações do SelectSort:");
    GeraVetorAleat(vetor);
    SelectSort(vetor,TAM_V);
}

void DevMode(){
    int operacao;
    puts("");
    puts("==========================================================================================="); 
    puts("Olá desenvolvedor! Bem vindo à interface de desenvolvimento do sistema");
    puts("Aqui você poderá checar as comparações e quantidades de trocas, além dos alg de ordenação.");
    puts("==========================================================================================="); 

    do{
        puts("");
        puts("");
        //Aqui tem que vir a quantidade de trocas e comparacoes das coisas !! 
        puts("");
        puts("");
        puts("Qual opção você gostaria de fazer?");
        puts("");
        puts("=============================================");
        puts("(0) Voltar ao sistema de Fila de prioridades");
        puts("(1) InsereHeap");
        puts("(2) RemoveHeap");
        puts("(3) ImprimeHeap");
        puts("(4) AlteraHeap");
        puts("(5) ChecaHeap");
        puts("(6) Heapfy");
        puts("(7) compara Heap com Quick e Select");
        puts("============================================");
        puts("");
        scanf("%d",&operacao);

        switch (operacao)
        {

        case 0:
            puts("Voltando ao sistema de Fila de Prioridades");
            break;
        case 1:
            InsereHeap();
            break;
        
        case 2:
            RemoveHeap();
            break;
        
        case 3:
            ImprimeHeap();
            break;
        
        case 4:
            AlteraHeap();
            break;

        case 5:
            ChecaHeap();
            break;
        
        case 6:
            Heapfy();
            break;
        
        case 7:
            //implementar las paradas
            ComparaAlg();
            break;
            
        default:
            puts("");
            printf("essa não é uma operação válida!");
            break;
        }

    } while (operacao != 0);

}

//nao sei se nao vai ter mais funcoes (tipo a sacodeHeap)

int main(){
    int operacao;

    puts("==================================================================================="); 
    puts("Olá Enfermeira Chefe! Bem vindo ao sistema de fila de prioridades do Hospital");
    puts("Feito por Breno Demio Padilha e Haico de Toledo Boehs para a disciplina de Alg 2");
    puts("==================================================================================="); 

    InicHeap();

    do{
        puts("");
        puts("");
        puts("Qual opção você gostaria de fazer?");
        puts("");
        puts("============================================");
        puts("(0) Sair do sistema");
        puts("(1) Inserir paciente na fila de espera");
        puts("(2) Chamar próximo paciente a ser atendido");
        puts("(3) Imprime todos na sala de espera");
        puts("(4) Altera a prioridade de algum paciente");
        puts("(5) Entrar no Dev Mode"); //o dev mode seria o modo que teria as comparações e o heapfy/checaheap
        puts("============================================");
        puts("");
        scanf("%d",&operacao);

        switch (operacao)
        {

        case 0:
            break;
        case 1:
            InsereHeap();
            break;
        
        case 2:
            RemoveHeap();
            break;
        
        case 3:
            ImprimeHeap();
            break;
        
        case 4:
            AlteraHeap();
            break;

        case 5:
            DevMode();
            break;
            
        default:
            puts("");
            printf("essa não é uma operação válida!");
            break;
        }

    } while (operacao != 0);
        
    puts("");
    puts("");
    puts("Sistema encerrando!");
}   

