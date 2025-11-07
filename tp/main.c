/* --------------------------------------------------------------------------------------
   Programa que implementa o Tipo Abstrato de Dados Heap,
   além dos algoritmos de ordenação Heap, Quick e Select Sort.
   Objetivo: Aprender a implementação do Heap e comparar ele com o Quick e Select sort
   Restricoes: o programa assuma que o usuario entrou com os valores corretos, inteiros.

   Autores: Breno Demio Padilha e Haico de Toledo Boehs 
   Disciplina: Algoritmos II
   Data da ultima atualizacao: 2025/2
----------------------------------------------------------------------------------------*/
//comparar algoritmos, double coisa no if é double comparacao? 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "heap.h"
#define TAM_V_MAX 1024
#define TAM_V_MIN 32
#define TAM_FILA_MAX 2000

/* cria um vetor de tam elementos e enche de numeros aleatorios de 0 a 999 */ 
void GeraVetorAleat(int vetor[], int tam){ 
    srand(time(NULL));
    for (int i = 1; i <= tam; i++)
    {
        vetor[i] = rand() % 1000;
    }
}

void ImprimeVetor(int vetor[], int tam){
    int i;
    puts("Vetor: ");
    for (i = 1; i < tam; i++)
        printf("%d ",vetor[i]);
    printf("%d\n",vetor[i]);

}


/* descobre entre 3 números qual é o menor*/
void Menor(int heap,int quick,int select){
    int menor = heap;
    if (select < menor)
        menor = select;
    if (quick < menor)
        menor = quick;

    if (menor == select){
        printf("o Select sort (%d).\n",select);
        return;
    }
    else if (menor == quick){
        printf("o Quick sort (%d).\n",quick);
        return;
    }
    else 
        printf("o Heap sort (%d).\n",heap);
}   

/* Compara o HeapSort com o Quick e com o Select */
void ComparaAlg(int tam){ 
    int vetor[tam+1];
    int trocas_select = 0;
    int comp_select = 0;
    int trocas_quick = 0;
    int comp_quick = 0;
    int trocas_heap = 0;
    int comp_heap = 0;
	int comp_heapfy = 0;
	int trocas_heapfy = 0;
	
    puts("");
    puts("Segue a comparação da performance em ordenação de 3 algoritmos para esse vetor:");
    GeraVetorAleat(vetor,tam);
    ImprimeVetor(vetor,tam);

    puts("trocas e comparações do HeapSort:");
    HeapSort(vetor,tam,&trocas_heap,&comp_heap,&comp_heapfy,&trocas_heapfy);
    ImprimeVetor(vetor,tam);
    printf("comparações: %d\n", comp_heap);
    printf("trocas: %d\n", trocas_heap);
    printf("trocas e comparações do heapfy:\n");
	printf("comparações: %d\n", comp_heapfy);
    printf("trocas: %d\n", trocas_heapfy);
    puts("");

    puts("trocas e comparações do QuickSort:");
    GeraVetorAleat(vetor,tam);
    QuickSort(vetor,1,tam,&trocas_quick,&comp_quick);
    ImprimeVetor(vetor,tam);
    printf("comparações: %d\n", comp_quick);
    printf("trocas: %d\n", trocas_quick);
    puts("");

    puts("trocas e comparações do SelectSort:");
    GeraVetorAleat(vetor,tam);
    SelectSort(vetor,tam, &trocas_select, &comp_select);
    ImprimeVetor(vetor,tam);
    printf("comparações: %d\n", comp_select);
    printf("trocas: %d\n", trocas_select);

    printf("O algoritmo com menos comparacoes é ");
    Menor(comp_heap,comp_quick,comp_select);
    printf("O algoritmo com menos trocas é ");
    Menor(trocas_heap,trocas_quick,trocas_select);
}

/* Função que libera o Buffer para conseguir ler strings */
void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    int operacao;
    int tam_fila;
    struct paciente fila[TAM_FILA_MAX];
    int prio;
    int nova_prio;
    char nome[100];
    int compHeapfy = 0;
    int trocasHeapfy = 0;
    
    puts("==================================================================================="); 
    puts("Olá Enfermeira Chefe! Bem vindo ao sistema de fila de prioridades do Hospital.");
    puts("Feito por Breno Demio Padilha e Haico de Toledo Boehs para a disciplina de Alg 2");
    puts("==================================================================================="); 

    InicHeap(fila,&tam_fila,TAM_FILA_MAX);

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
        puts("(5) Gerar vetor aleatório de 32 elementos");
        puts("(6) Gerar vetor aleatório de 1024 elementos");
        puts("============================================");
        puts("");

        /* evita chars por exemplo de quebrarem o programa */
        if(scanf("%d",&operacao) != 1){
            printf("Por favor insira um número.\n");
            LimpaBuffer();
            continue;    
        }

        switch (operacao)
        {

        case 0:
            break;
        case 1:
            LimpaBuffer();
            printf("Digite o nome do paciente: ");
            scanf("%99[^\n]", nome);
            LimpaBuffer();
            printf("Digite a prioridade do paciente: ");
            scanf("%d", &prio);
            if(prio < 0){
                printf("A prioridade deve ser positiva.");
                break;
            }
            LimpaBuffer();
            InsereHeap(fila,&tam_fila,prio,nome);
            printf("paciente inserido na fila!");
            break;
        
        case 2:
            if(tam_fila == 0){
                printf("Não há pacientes na fila!");
                break;
            }
            printf("Chamando paciente (nome: %s | prio: %d)", fila[1].nome,fila[1].prioridade);
            RemoveHeap(fila,&tam_fila,&compHeapfy,&trocasHeapfy);
            printf("Comparações e trocas do Heapfy (usado na função):\n");
        	printf("Comparações: %d\n", compHeapfy);
        	printf("Trocas: %d\n", trocasHeapfy);
            compHeapfy = 0;
            trocasHeapfy = 0;
            break;
        
        case 3:
            ImprimeHeap(fila,tam_fila);
            break;
        
        case 4:
            LimpaBuffer();
            printf("Digite o nome do paciente: ");
            scanf("%99[^\n]", nome);
            LimpaBuffer();
            printf("Digite a prioridade do paciente: ");
            scanf("%d", &prio);
            printf("Digite a nova prioridade do paciente: ");
            scanf("%d", &nova_prio);
            if(nova_prio < 0){
                printf("A prioridade deve ser positiva.");
                break;
            }
            LimpaBuffer();
            if(!AlteraHeap(fila,tam_fila,prio, nova_prio,nome, &compHeapfy, &trocasHeapfy))
                printf("Não existe esse paciente!");
            else {
                printf("Prioridade atualizada!");
            	printf("Comparações e trocas do Heapfy (usado na função):\n");
            	printf("Comparações: %d\n", compHeapfy);
            	printf("Trocas: %d\n", trocasHeapfy);
            	compHeapfy = 0;
            	trocasHeapfy = 0;
            }
            break;

        case 5:
            ComparaAlg(TAM_V_MIN);
            break;
            
        case 6:
            ComparaAlg(TAM_V_MAX);
            break;
            
        default:
            puts("");
            printf("essa não é uma operação válida!");
            break;
        }

    } while ((operacao != 0));
        
    puts("");
    puts("");
    puts("Sistema encerrando!");
}   

