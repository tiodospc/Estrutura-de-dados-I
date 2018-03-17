#include <stdio.h>


int main(){
	
int  vet[5], i;	
	
p= vet;

printf("Digite 5 numeros\n");
	for(i=0; i<5; i++){
		scanf("%d", &vet[i]);
		}
	for(i=0; i<5; i++){
		printf("\n%d\n", *(vet+i));
		}
	
return 0;}

/*
2 forma de fazer passando de vetor para um ponteiro (sendo que vetor já e um ponteiro)
#include <stdio.h>


int main(){
	
int *p, vet[5], i;	
	
p= vet;

printf("Digite 5 numeros\n");
	for(i=0; i<5; i++){
		scanf("%d", vet[i]);
		}
	for(i=0; i<5; i++){
		printf("%d\n", *(p)++);
		}
	
	
	
	
	
	
	
return 0;} */
