#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct info {
    int valor;
} info;

typedef struct nodo {
    info elemento;
    struct nodo *next;
} nodo;


int resto(int num) { //função que calcula em qual posição o novo elemento sera inserido
    return (num % MAX);
}

int buscar(int num, nodo *hash_table[]) { //função que busca se o elemento esta na tabela
    int h = resto(num);
    nodo *bus = hash_table[h];

    while(bus != NULL) {
        if(bus->elemento.valor == num) { //verifica se o numero que o usuario comentou e igual o valor da linha
            return h; //retorna o valor da linha
        }
        bus = bus->next;
    }

    return -1; //se não achou nenhum eleemento correspondente

}


void inserir(info no, nodo *hash_table[]) {
    nodo *novo;
    int num = no.valor;
    int h;
    //precisamos verificar se o numero que esta sendo inserido ja consta na tabela chamando a função busca
    if(buscar(num, hash_table) != -1) {
        printf("Já existe esse numero na tabela\n");
        return;
    }
    h = resto(num);
    novo = malloc(sizeof(struct nodo));
    novo->elemento = no;
    novo->next = hash_table[h];
    hash_table[h] = novo;
}

void printar(nodo *hash_table[]) {
    nodo *p;
    int i;
    for(i = 0; i < MAX; i++) {
        printf("\n[%d] ", i);
        if(hash_table[i] != NULL) {
            p  = hash_table[i];

            while(p != NULL) {
                printf("[%d] -> ", p->elemento.valor);
                p = p->next;
            }

            printf("NULL");
        }
    }
    printf("\n");
}

void printarlinha(int i, nodo *hash_table[]) {
    nodo *p;

    if(i != -1) {

        printf("Elemento encontrado na linha: %d\n", i);
        printf("\n[%d] ", i);
        p = hash_table[i];

        while(p != NULL) {
            printf("[%d] -> ", p->elemento.valor);
            p = p->next;
        }
        printf("NULL");
    }

}

int main() {
    nodo *hash_table[MAX];
    info no;
    int op, num, i;

    for(i = 0; i <= MAX - 1; i++) //deixando todas as linhas da tabela = NULL
        hash_table[i] = NULL;

    do {
        printf("(1) Inserir um elemento na tabela\n");
        printf("(2) Procurar um elemento\n");
        printf("(3) Mostrar a tabela hash\n");

        scanf("%d", &op);
        switch(op) {

        case 1:
            scanf("%d", &no.valor);
            inserir(no, hash_table);
            break;

        case 2:
            scanf("%d", &num);
            i = buscar(num, hash_table);
            printarlinha(i, hash_table);
            break;

        case 3:
            printar(hash_table);
            break;
        }
    } while(op != 0);

    return 0;
}
