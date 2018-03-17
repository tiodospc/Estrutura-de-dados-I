#include <stdio.h>


int main(){
	
int *p, vet[5], i;	
	
p= vet;

printf("Digite 5 numeros\n");
	for(i=0; i<5; i++){
		scanf("%d", &vet[i]);
		}
	for(i=0; i<5; i++){
		printf("\n%d\n", *(p)++);
		}
	
return 0;}
