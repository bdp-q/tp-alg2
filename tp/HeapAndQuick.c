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
	char nome;
};

/*funções vem aqui, nenhuma dela tem os parametros ou tipo correto ainda*/
void InicHeap(){
    puts("iniciou o heap!");
}

void InsereHeap(){
    puts("inseriu no heap");
}

void RemoveHeap(){
    puts("Removeu no heap");
}

void ImprimeHeap(){
    puts("imprimiu no heap");
}

void AlteraHeap(){
    puts("Alterou no heap");
}

void ChecaHeap(){
    puts("ve se é heap");
}

void Heapfy(){
    puts("transformou em heap");
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

