#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
typedef struct contato {
    char nome[50], numero[30];
} Contato;
 
typedef struct lista {
    Contato n;
    struct contato *p;  // Ponteiro para o próximo nó
    struct contato *a; 
    // int size;    
} LISTA;

Contato entrada_contato(void);
LISTA *entrada_lista(LISTA *n, Contato l);
void saida_contato(Contato n);
void saida_lista(LISTA *l);
LISTA *deletar_contato(LISTA *l, const char *nome);
LISTA *atualizar_contato(LISTA *l, const char *nome, Contato novoContato);
bool listaVazia(LISTA *l);
 
int main(void) {
    char op;
    LISTA *l = NULL;
 
    do {
        system("clear"); 
        printf("1 - Adicionar um contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Deletar um contato\n");
        printf("4 - Atualizar um contato\n");
        printf("5 - Sair\n");
        printf("\nDigite uma opcao: ");
        scanf(" %c", &op);
        __fpurge(stdin); 
 
        switch (op) {
            case '1':
                system("clear");  // Limpa a tela no Windows
                l = entrada_lista(l, entrada_contato());
                printf("Dados gravados na lista\n");
                break;
            case '2':
                saida_lista(l);
                break;
            case '3':
                {
                saida_lista(l);
                    char nome[50];
                    printf("Digite o nome do contato a ser deletado: ");
                    fgets(nome, sizeof(nome), stdin);
                    __fpurge(stdin);  // Limpa o buffer de entrada em ambientes Windows
                    l = deletar_contato(l, nome);
                    saida_lista(l);
                    break;
                }
            case '4':
                {
                saida_lista(l);
                    char nome[50];
                    Contato novoContato;
                    printf("Digite o nome do contato a ser atualizado: ");
                    fgets(nome, sizeof(nome), stdin);
                    __fpurge(stdin);  // Limpa o buffer de entrada em ambientes Windows
                    novoContato = entrada_contato();
                    l = atualizar_contato(l, nome, novoContato);
                    saida_lista(l);
                    break;
                }
            case '5':
                printf("Saindo...\n");
                break;
            default:
                printf("Erro! Opcao invalida\n");
        }
 
        printf("Pressione qualquer tecla para continuar");
        getchar();
    } while (op != '5');
 
    return 0;
}
 
Contato entrada_contato(void) {
    Contato n;
 
    printf("Digite o nome: ");
    fgets(n.nome, sizeof(n.nome), stdin);
    __fpurge(stdin);  // Limpa o buffer de entrada em ambientes Windows
    printf("Digite o telefone: ");
    fgets(n.numero, sizeof(n.numero), stdin);
    __fpurge(stdin); // Limpa o buffer de entrada em ambientes Windows
 
    return n;
}
 
LISTA *entrada_lista(LISTA *l, Contato n) {
    
    LISTA *novo = (LISTA *)malloc(sizeof(LISTA));
    novo->n = n;
    novo->p = l;      // Ponteiro para o próximo nó
    novo->a = NULL;   // Nó anterior é NULL no início
    // Se a lista não estiver vazia, atualiza o ponteiro para o nó anterior
    if (!listaVazia(l)) {
        l->a = novo;
    }
 
    return novo;
}
 
void saida_contato(Contato n) {
    printf("%s\t", n.nome);
    printf("%s\t", n.numero);
    printf("\n");
}
 
void saida_lista(LISTA *l) {
    system("clear");  // Limpa a tela no Windows
    printf("NOME\t\tNUMERO\n");
 
    while (l != NULL) {
        saida_contato(l->n);
        l = l->p;
    }
}
 
LISTA *deletar_contato(LISTA *l, const char *nome) {
    LISTA *atual = l;
 
    while (atual != NULL) {
        if (strcmp(atual->n.nome, nome) == 0) {
            LISTA *anterior = atual->a;
            LISTA *proximo = atual->p;
 
            if (anterior != NULL) {
                anterior->p = proximo;
            } else {
                l = proximo;
            }
 
            if (proximo != NULL) {
                proximo->a = anterior;
            }
 
            free(atual);
            printf("Contato deletado com sucesso.\n");
            return l;
        }
 
        atual = atual->p;
    }
 
    printf("Contato nao encontrado.\n");
    return l;
}

bool listaVazia(LISTA *l) {
    return l == NULL;
}
 
LISTA *atualizar_contato(LISTA *l, const char *nome, Contato novoContato) {
    LISTA *atual = l;
 
    while (atual != NULL) {
        if (strcmp(atual->n.nome, nome) == 0) {
            // Atualiza o contato
            strcpy(atual->n.nome, novoContato.nome);
            strcpy(atual->n.numero, novoContato.numero);
 
            printf("Contato atualizado com sucesso.\n");
            return l;
        }
 
        atual = atual->p;
    }
 
    printf("Contato nao encontrado.\n");
    return l;
}