#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int resto(int num) {
}




int main() {

    int i, j, aux, v[TAM];

    for(i = 0; i < TAM; i++) {
        v[i] = (rand() % 100);
    }

    printf("sem onrdenação:\n");

    for(i = 0; i < TAM; i++) {
        printf("[%d] ", v[i]);
    }

    for(i = 1; i < TAM; i++) {
        aux = v[i];
        j = i - 1;

        while((j >= 0) && (aux < v[j])) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }

    printf("\nordenados:\n");
    for(i = 0; i < TAM; i++) {
        printf("[%d] ", v[i]);
    }


    return 0;
}


