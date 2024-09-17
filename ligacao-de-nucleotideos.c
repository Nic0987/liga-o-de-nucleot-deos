/* DATA: 05/07/2023
 ACAD�MICO: NICOLAS RYAN 
 RA (REGISTRO ACAD�MICO): 22168634-5
 CURSO: ENGENHARIA DE SOFTWARE              
 DISCIPLINA: ESTRUTURA DE DADOS I
 MAPA - CONVERS�O DE NUCLEOT�DEOS.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estrutura do n� da fila
typedef struct no_fila {
    char nucleotideo;
    struct no_fila* proximo;
} no_fila;

//Estrutura do n� da pilha
typedef struct no_pilha {
    char nucleotideo;
    struct no_pilha* proximo;
} no_pilha;

// Vari�veis globais
typedef no_fila* ptr_fila;
typedef no_pilha* ptr_pilha;
ptr_fila fila;
ptr_pilha pilha;

// Fun��o para colocar um elemento na fila
void inserirFila(char nucleotideo) {
    ptr_fila novoNo = (ptr_fila)malloc(sizeof(no_fila));
    novoNo->nucleotideo = nucleotideo;
    novoNo->proximo = NULL;

    if (fila == NULL) {
        fila = novoNo;
    } else {
        ptr_fila temp = fila;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

// Fun��o para remover um elemento da fila
void excluirFila() {
    if (fila == NULL) {
        printf("Fila vazia.\n");
    } else {
        ptr_fila temp = fila;
        fila = fila->proximo;
        free(temp);
    }
}

// Fun��o para imprimir a fila
void imprimirFila() {
    ptr_fila temp = fila;
    while (temp != NULL) {
        printf("%c", temp->nucleotideo);
        temp = temp->proximo;
    }
    printf("\n");
}

// Fun��o para colocar um elemento na pilha
void inserirPilha(char nucleotideo) {
    ptr_pilha novoNo = (ptr_pilha)malloc(sizeof(no_pilha));
    novoNo->nucleotideo = nucleotideo;
    novoNo->proximo = pilha;
    pilha = novoNo;
}

// Fun��o para remover um elemento da pilha
void excluirPilha() {
    if (pilha == NULL) {
        printf("Pilha vazia.\n");
    } else {
        ptr_pilha temp = pilha;
        pilha = pilha->proximo;
        free(temp);
    }
}

// Fun��o para imprimir a pilha
void imprimirPilha() {
    ptr_pilha temp = pilha;
    while (temp != NULL) {
        printf("%c", temp->nucleotideo);
        temp = temp->proximo;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op;
    int ocorreuErro= 0;
	fila = NULL;
    pilha = NULL;

    do {
        printf("------------------------------------------------------\n");
        printf("LIGA��ES ENTRE OS NUCLEOT�DEOS \n");
        printf("------------------------------------------------------\n");
        printf("MENU DE OP��ES:\n");
        printf("------------------------------------------------------\n");
        printf(" 1. INSERIR SEQU�NCIA DE NUCLEOT�DEOS (A - C - T - G).\n");
        printf(" 2. CONVERTER ELEMENTOS PARA DUPLA FITA (DNA).\n");
        printf(" 0. SAIR DA APLICA��O.\n");
        printf("------------------------------------------------------\n");
        printf("DIGITE A OP��O DESEJADA: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                system("cls");
                char sequencia[100];
                printf("Digite a Sequ�ncia de Nucleot�deos: ");
                scanf("%s", sequencia);
                int tamanho = strlen(sequencia);
                int i;
                for (i = 0; i < tamanho; i++) {
                char nucleotideo = sequencia[i];
                    if (nucleotideo == 'A' || nucleotideo == 'C' || nucleotideo == 'T' || nucleotideo == 'G') {
                        inserirFila(nucleotideo);
                    } else {
                        printf("Nucleot�deo Inv�lido!\n", nucleotideo);
                        system ("pause");
						system ("cls");
                        ocorreuErro = 1;
                        break;
                    }
                }
                if (ocorreuErro != 1) {
                printf("Os Elementos foram armazenados na Fila!\n");
                printf("\n");
                system("pause");
                system("cls"); }
                break;
            }

            case 2: {
                system("cls");
                if (fila == NULL && pilha == NULL) {
                printf("A Fila e a Pilha Est�o Vazias, Por Favor Insira Dados V�lidos! \n\n");
                system ("pause");
                system("cls");
					break;
                }
                ptr_fila lista_temp = fila;
                while (lista_temp != NULL) {
                    char nucleotideo = lista_temp->nucleotideo;
                    lista_temp = lista_temp->proximo;

                    switch (nucleotideo) {
                        case 'A':
                            inserirPilha('T');
                            break;
                        case 'T':
                            inserirPilha('A');
                            break;
                        case 'C':
                            inserirPilha('G');
                            break;
                        case 'G':
                            inserirPilha('C');
                            break;
                        default:
                            printf("Nucleot�deo Inv�lido\n");
                            ocorreuErro = 1;
                            break;
                    
                    }
                }
                    printf("A Sequ�ncia de Nucleot�deos na Fila �: ");
                    imprimirFila();
                    printf("A Sequ�ncia de Nucleot�deos na Pilha �: ");
                    imprimirPilha();
                    printf("\n");

                    while (fila != NULL) {
                        excluirFila();
                    }
                    while (pilha != NULL) {
                        excluirPilha();
                    }

                system("pause");
                system("cls");
                break;
            }

            case 0: {
                system("cls");
                printf("Saindo do Programa...\n");
                break;
            }

            default:
                printf("Op��o inv�lida. Tente Novamente!\n");
                system ("pause");
				system ("cls");
			    break;
        }

    } while (op != 0);

    return 0;
}

