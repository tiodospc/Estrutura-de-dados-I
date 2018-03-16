#include <stdio.h>


int somaa(int *n1, int *n2){

return *n1+*n2;
}


int main(){

int a,b;

printf("digite dois numeros: ");

scanf("%d", &a);
scanf("%d", &b);


printf("Resultado: %d\n", somaa(&a,&b));


return 0;}
