#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50], numero[30];
} Contato;

typedef struct lista {
    Contato n;
    struct lista *p;
    struct lista *a;
} LISTA;

Contato entrada_contato(void);
LISTA *entrada_lista(LISTA *n, Contato l);
void saida_contato(Contato n);
void saida_lista(LISTA *n);

int main(void) {
    char op;
    LISTA *l = NULL;

    do {
        system("clear");  // Limpa a tela no Linux
        printf("1 - Adicionar um contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Sair\n");
        printf("\nDigite uma opcao: ");
        scanf(" %c", &op);
         __fpurge(stdin);  // Limpa o buffer de entrada no Linux

        switch (op) {
            case '1':
                system("clear");  // Limpa a tela no Linux
                l = entrada_lista(l, entrada_contato());
                printf("Dados gravados na lista\n");
                break;
            case '2':
                saida_lista(l);
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Erro! Opcao invalida\n");
        }
        printf("Pressione qualquer tecla para continuar");
        getchar();
    } while (op != '3');

    return 0;
}

Contato entrada_contato(void) {
    Contato n;

    printf("Digite o nome: ");
    fgets(n.nome, sizeof(n.nome), stdin);
    __fpurge(stdin);  // Limpa o buffer de entrada no Linux
    printf("Digite o telefone: ");
    fgets(n.numero, sizeof(n.numero), stdin);
    __fpurge(stdin);  // Limpa o buffer de entrada no Linux

    return n;
}

LISTA *entrada_lista(LISTA *l, Contato n) {
    LISTA *novo = (LISTA *)malloc(sizeof(LISTA));
    novo->n = n;
    novo->p = l;
    return novo;
}

void saida_contato(Contato n) {
    printf("%s\t", n.nome);
    printf("%s\t", n.numero);
}

void saida_lista(LISTA *l) {
    system("clear");  // Limpa a tela no Linux
    printf("SALA\tNOME\tSEMANA\tSEMESTRE\n\n");

    while (l != NULL) {
        saida_contato(l->n);
        l = l->p;
    }
}
